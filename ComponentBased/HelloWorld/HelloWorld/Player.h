#pragma once
#include <conio.h>
#include "GameObject.h"

class Enemy;
class MoveScript;

class Player :
    public GameObject
{
	MoveScript* moveScript;

	auto processInput()
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
	}

	GameObject* findNearestTarget();

public:
	Player(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, const Dimension& dim = { 1,1 });

	void start() override;
	void update() override;
};

