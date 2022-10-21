#pragma once
#include <conio.h>
#include "GameObject.h"

class Player :
    public GameObject
{

	auto processInput()
	{
		auto pos = getPos();
		if (InputSystem::GetKey('w')) {
			pos.y--;
		}
		else if (InputSystem::GetKey('a')) {
			pos.x--;
		}
		else if (InputSystem::GetKey('s')) {
			pos.y++;
		}
		else if (InputSystem::GetKey('d')) {
			pos.x++;
		}

		setPos(pos);

	}

public:
    Player(int x, int y, Screen& screen) 
		: GameObject('>', x, y, screen) 
	{}


	void update() override
	{
		processInput();
	}

	
};

