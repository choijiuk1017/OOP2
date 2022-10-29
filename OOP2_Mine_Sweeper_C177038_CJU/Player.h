#pragma once
#include "GameObject.h"
#include <conio.h>
#include "Screen.h"


class Player : public GameObject
{
	//Ű���� �Է�
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
		else if (input.getKeyDown(0x45)) //E ������ Ž��
		{
			check(pos);
		}
		else if (input.getKeyDown(0x46)) //F ������ ���
		{
			drawFlag(mineNum, pos);
		}
		setPos(pos);
	}

	//���콺 �Է�
	auto processMouseInput(int mineNum)
	{
		auto pos = input.getMousePosition();
		if (input.getMouseButtonDown(0)) //��Ŭ�� Ž��
		{
			check(pos);
		}
		else if (input.getMouseButtonDown(1)) //��Ŭ�� ���
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

	//ĭ ���� Ȯ���ϴ� �Լ�
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


	//��� �ȴ� �Լ�
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

	//�÷��� ��� ����
	void printInformation()
	{
		Borland::GotoXY(0, 16);

		printf("W, A, S, D: Ű���� �̵�\n");
		printf("E: �ش� ��ġ Ȯ��\n");
		printf("F: ��� �ȱ�\n");
		printf("��Ŭ��: Ȯ��\n");
		printf("��Ŭ��: ���\n");
	}

};


