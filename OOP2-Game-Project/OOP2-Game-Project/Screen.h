#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;
class Screen
{
	char* lines;
	int n_rows;
	int n_cols;

public:

	Screen(int n_rows, int n_cols) :n_rows(n_rows), n_cols(n_cols), lines(new char[n_rows * n_cols + 1])
	{
		Borland::Initialize();
		clear();
	}

	void clear()
	{
		memset(lines, ' ', n_rows * n_cols);

		for (int i = 0; i < n_rows; i++)
		{
			lines[i * n_rows + n_rows] = '\n';
		}
		lines[n_rows * n_cols] = '\0';
	}

	void draw(const Position& pos, char shape)
	{

	}
	void render()
};

