#pragma once
#include "GameObject.h"
#include <conio.h>
#include "MainTable.h"


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

	//ĭ ���� Ȯ���ϴ� �Լ�
	void check(const Position& pos);

	//��� �ȴ� �Լ�
	void drawFlag(int& Num, const Position& pos);

	//�÷��� ��� ����
	void printInformation();

};


