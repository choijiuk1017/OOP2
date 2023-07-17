#pragma once
#include "GameObject.h"
#include <conio.h>
#include "MainTable.h"


class Player : public GameObject
{
	//키보드 입력
	auto processInput(int mineNum)
	{
		auto pos = getPos();
		if (input.getKeyDown(0x57))
		{
			pos.y--;
		}
		else if (input.getKeyDown(0x41))
		{
			pos.x--;
		}
		else if (input.getKeyDown(0x53))
		{
			pos.y++;
		}
		else if (input.getKeyDown(0x44))
		{
			pos.x++;
		}
		else if (input.getKeyDown(0x45)) //E 누르면 탐색
		{
			check(pos);
		}
		else if (input.getKeyDown(0x46)) //F 누르면 깃발
		{
			drawFlag(mineNum, pos);
		}
		setPos(pos);
	}
	//마우스 입력
	auto processMouseInput(int mineNum)
	{
		auto pos = input.getMousePosition();
		if (input.getMouseButtonDown(0)) //좌클릭 탐색
		{
			check(pos);
		}
		else if (input.getMouseButtonDown(1)) //우클릭 깃발
		{
			drawFlag(mineNum, pos);
		}
	}


public:
	Player(int x, int y, MainTable& mainTable, NumTable& numTable, InputSystem& input)
		: GameObject('>', x, y, mainTable, numTable, input) 
	{}

	void update(int mineNum) override
	{
		processInput(mineNum);
		processMouseInput(mineNum);
	}

	void draw() override
	{
		GameObject::draw();
	}

	//칸 정보 확인하는 함수
	void check(const Position& pos);

	//깃발 꽂는 함수
	void drawFlag(int& Num, const Position& pos);

	//플레이 방법 제공
	void printInformation();

};


