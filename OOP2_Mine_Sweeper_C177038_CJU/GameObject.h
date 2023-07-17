#pragma once
#include <iostream>
#include "Utils.h"
#include "MainTable.h"
#include "NumTable.h"
#include "InputSystem.h"

using namespace std;


class GameObject
{
	Position pos;
	char* shape;
	Dimension dim;

protected:
	MainTable& mainTable;
	NumTable& numTable;
	InputSystem& input;

public:
	GameObject(char shape, int x, int y, MainTable& mainTable, NumTable& numTable, InputSystem & input)
		: pos(x, y), shape(nullptr), dim(1, 1), mainTable(mainTable), numTable(numTable), input(input)
		
	{
		this->shape = (char*)new char[dim.size() + 1];
		this->shape[0] = shape;
		this->shape[dim.size()] = '\0';
	}

	virtual ~GameObject() {
		delete[] shape;
	}

	auto getPos() const { return pos; }

	void setPos(const Position& pos) 
	{
		if (mainTable.checkValidPos(pos) == false)
			return;
		this->pos.x = pos.x; this->pos.y = pos.y; 
	}

	auto getShape() const { return shape[0]; }

	virtual void draw()
	{
		mainTable.DrawMain(pos, shape[0]);
	}

	virtual void update(int mineNum) {}
};

