#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "MoveScript.h"
#include "Bullet.h"
#include "Utils.h"
#include <memory>

using namespace std;

Player::Player(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, const Dimension& dim)
	: GameObject(shape, pos, screen, input, dim), moveScript(nullptr)
{
	start();
}

void Player::start()
{
	moveScript = new MoveScript(this);
	addComponent<Component>(moveScript);
}

GameObject* Player::findNearestTarget()
{
	GameObject* target = nullptr;
	auto myPos = getPos();
	double dist = DBL_MAX;

	for (auto& obj : objs)
	{
		auto enemy = dynamic_cast<Enemy*>(obj.get());
		if (enemy == nullptr) continue;

		auto pos = enemy->getPos();
		auto diff = pos - myPos;
		auto result = diff.sqrtMagnitude();
		if (target == nullptr || result < dist) {
			dist = result;
			target = enemy;
		}
	}
	return target;
}


void Player::update() 
{
	if (input.getMouseButtonDown(0))
	{
		auto target = findNearestTarget();
		if (target != nullptr) {
			moveScript->setTarget(target);
			return;
		}
		Position<float> mousePos = input.getMousePosition();
		moveScript->moveTowards(mousePos);
	}
	else if (input.getMouseButton(1))
	{
		auto target = findNearestTarget();
		auto mousePos = input.getMousePosition();
		Position<float> pos = mousePos;
		if (target != nullptr) {
			pos = target->getPos();
		}
		auto direction = pos - getPos();
		if (direction == Position<float>(0.0f, 0.0f)) direction = Position<float>(1.0f, 0.0f);
		pendings.push_back(new Bullet(direction, getPos(), screen, input));
	}
	
	processInput();
}
