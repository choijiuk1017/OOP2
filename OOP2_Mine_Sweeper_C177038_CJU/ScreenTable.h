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

	void Render()
	{
		Borland::GotoXY(0, 0);
		printf("%s", table);
	}

	~ScreenTable() { delete[] table; }
};

