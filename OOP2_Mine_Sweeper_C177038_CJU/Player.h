#pragma once
#include "GameObject.h"
#include <conio.h>
#include "Screen.h"


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
	Player(int x, int y, Screen& screen, InputSystem& input)
		: GameObject('>', x, y, screen, input) 
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
	void check(const Position &pos)
	{
		Borland::GotoXY(0, 13);	

		char mineNum = screen.table2Lines(pos);

		if (mineNum >= '*' && mineNum <= '/')
		{
			mineNum = '*';
			screen.draw(pos, mineNum);
			printf("Mine!");
			exit(0);
		}

		if (mineNum == '0')
		{
			screen.checkAround(pos.x, pos.y);
		}

		screen.draw(pos, mineNum);
	}


	//깃발 꽂는 함수
	void drawFlag(int &Num, const Position& pos)
	{
		Borland::GotoXY(0, 14);

		screen.draw(pos, 'F');

		static int mineNum = Num;
		static int flagNum = Num;

		flagNum--;

		printf("flag: %d\n", flagNum);

		if (screen.table2Lines(pos) == '*')
		{
			mineNum--;
			screen.checkFlag(pos);
			printf("mine: %d\n", mineNum);
		}

		if (mineNum == 0)
		{
			printf("You Win!!\n");
			exit(0);
		}
		else if(flagNum == 0 && mineNum > 0)
		{
			printf("No more flag\n");
			exit(0);
		}
	}

	//플레이 방법 제공
	void printInformation()
	{
		Borland::GotoXY(0, 16);

		printf("W, A, S, D: 키보드 이동\n");
		printf("E: 해당 위치 확인\n");
		printf("F: 깃발 꽂기\n");
		printf("좌클릭: 확인\n");
		printf("우클릭: 깃발\n");
	}

};


