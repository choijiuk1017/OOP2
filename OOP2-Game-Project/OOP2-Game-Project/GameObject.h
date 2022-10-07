#pragma once
#include "Utils.h"

class GameObject
{
	Position pos; //Utils 헤더에 있는 구조체 사용
	char* shape; //포인터를 사용하지만 1바이트만 사용
	Dimension dim; //몇차원인지 확인
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

