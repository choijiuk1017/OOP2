#pragma once
#include "Utils.h"

class GameObject
{
	Position pos; //Utils ����� �ִ� ����ü ���
	char* shape; //�����͸� ��������� 1����Ʈ�� ���
	Dimension dim; //���������� Ȯ��
public:
	GameObject(char shape, int x, int y)
		: pos(x,y) , shape(nullptr) , dim(1,1)
	{
		this->shape = (char*)new char[dim.size()+ 1];
		this->shape[0] = shape;
		this->shape[dim.size()] = '|0';
	}
	virtual ~GameObject()
	{
		delete[] shape;
	}

	Position getPos() const { return pos; }

	void setPos(const Position& pos)
	{
		this->pos.x = pos.x;
		this->pos.y = pos.y;
	}

	char getShape() const {return shape[0]; }


};

