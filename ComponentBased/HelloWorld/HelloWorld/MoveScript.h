#pragma once
#include "Component.h"
#include "GameObject.h"
#include "Utils.h"

using namespace std;

class MoveScript :
    public Component
{
    GameObject* target;
	Position<float> targetPos;
	Position<float> direction;

public:
    MoveScript(GameObject* gameObject) : Component(gameObject), 
		target(nullptr), targetPos(Position<float>::InvalidPosition),
		direction(Position<float>::InvalidPosition)
	{}

    void update() override {
		if (direction != Position<float>::InvalidPosition) {
			gameObject->setPos(gameObject->getPos() + direction * 0.1f);
			if ((gameObject->getScreen()).checkValidPos(gameObject->getPos()) == false) {
				direction = Position<float>::InvalidPosition;
				gameObject->setEnabled(false);
			}
			return;
		}

		if (targetPos == Position<float>::InvalidPosition) return;
		
		auto pos = gameObject->getPos();

		if (targetPos == pos) {
			if (target) {
				target->setEnabled(false);
				target = nullptr;
			}
			gameObject->setPos(Position<int>(targetPos));
			targetPos = Position<float>::InvalidPosition;
			return;
		}
		gameObject->setPos(pos.moveForward(targetPos, 1.f));
    }

	void setTarget(GameObject* target) { this->target = target; targetPos = target->getPos(); }

	void moveTowards(const Position<float>& pos) { this->targetPos = pos;  }

	void moveToDirection(const Position<float>& dir) { this->direction = dir; }

};

