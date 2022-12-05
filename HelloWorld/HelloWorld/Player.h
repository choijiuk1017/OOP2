#pragma once
#include <conio.h>
#include "GameObject.h"

class Enemy;

class Player :
    public GameObject
{
	GameObject* target;
	Position<float> targetPos;

	void processInput();

	void move()
	{
		auto pos = getPos();
		if (!target) {
			if (targetPos == Position<float>::InvalidPosition) 
				return;
		}
		else {
			targetPos = target->getPos();
		}
		if ( targetPos == pos) {
			if (target) {
				target->setEnabled(false);
				target = nullptr;
			}
			setPos(Position<int>(targetPos));
			targetPos = Position<float>::InvalidPosition;
			return;
		}
		setPos(pos.moveForward(targetPos, 1.f));
	}

	GameObject* findNearestTarget();


public:
	Player(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, Dimension dim = { 1,1 });
	Player(const Player& other) : Player(other.getShape(), other.getPos(), other.screen, other.input, other.getDimension())
	{
		cout << "player copy constructor[" << this << "]:" << getPos() << endl;
	}
	void update() override;

	void draw() override
	{	
		GameObject::draw();
	}

	void setTarget(GameObject* target) { this->target = target; }
	
};

