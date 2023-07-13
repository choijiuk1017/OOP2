#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;
class ScreenTable
{
	char* table;

	int rows;
	int cols;

protected:
	int pos2offset(int x, int y, int cols)
	{
		return y * cols + x;
	}

public:
	ScreenTable(int rows = 10, int cols = 11)
		:rows(rows), cols(cols),
		table(new char[rows * cols + 1])
	{

	}

	virtual void Clear() {}
	virtual void Draw() {}

	virtual void Render()
	{
		Borland::GotoXY(0, 0);
		printf("%s", table);
	}

	auto checkValidPos(const Position& pos) const
	{
		return (pos.x >= 0 && pos.x < cols - 1
			&& pos.y >= 0 && pos.y < rows);
	}

	~ScreenTable() { delete[] table; }
};

