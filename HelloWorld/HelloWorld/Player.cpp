#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include <memory>

using namespace std;


Player::Player(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, Dimension dim)
	: GameObject(shape, pos, screen, input, dim), target(nullptr), targetPos(Position<float>::InvalidPosition)
{
	cout << "player constructor[" << this << "]:" << pos << endl;
}



GameObject* Player::findNearestTarget()
{
	GameObject* target = nullptr;
	auto myPos = getPos();
	double dist = DBL_MAX;

	for (auto obj : objs)
	{
		auto enemy = dynamic_cast<Enemy*>(obj);
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


void Player::processInput()
{
	auto pos = getPos();
	if (input.getKey(0x57)) {
		pos.y--;
	}
	if (input.getKey(0x41)) {
		pos.x--;
	}
	if (input.getKey(0x53)) {
		pos.y++;
	}
	if (input.getKey(0x44)) {
		pos.x++;
	}
	setPos(pos);
	if (input.getKeyDown(VK_SPACE))
	{
		new Enemy("\xB0\xB0", { rand()%80, rand()%20}, screen, input, {2, 1});
	}
}

void Player::update() 
{	
	if (input.getMouseButtonDown(0))
	{
		auto target = findNearestTarget();
		if (target != nullptr) {
			setTarget(target);
			return;
		}
		auto mousePos = input.getMousePosition();
		targetPos = mousePos;
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
		if (direction == Position<float>( 0.0f, 0.0f) ) direction = Position<float>(1.0f, 0.0f);
		new Bullet(direction, getPos(), screen, input);
	}
	
	processInput();
	move();
}
