#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "Utils.h"

using namespace std;

class Screen
{
	char* lines;
	int n_rows;
	int n_cols;
	const int n_extra_rows;
	const int n_extra_cols;

	auto pos2offset(int x, int y, int n_cols) const
	{
		return y * n_cols + x;
	}

public:
	Screen(int n_rows, int n_cols)
		: n_rows(n_rows), n_cols(n_cols), n_extra_rows(20), n_extra_cols(20),
		lines(new char[sizeof(char)* n_rows * n_cols + 1])
	{
		string mode = "mode con:cols=" + to_string(n_cols + n_extra_cols);
		mode += " lines=" + to_string(n_rows + n_extra_rows);
		std::system(mode.c_str());
		std::system("chcp 437");

		Borland::Initialize(n_cols + n_extra_cols);
		clear();
	}

	virtual ~Screen() { delete[] lines; }

	void clear()
	{
		memset(lines, ' ', sizeof(char) * n_rows * n_cols );
	}

	void draw(const Position<int>& pos, char shape)
	{
		static char internalShape[2] = { 0 };

		internalShape[0] = shape; internalShape[1] = NULL;
		draw(pos, internalShape, { 1,1 });
	}

	auto checkValidPos(const Position<int>& pos) const
	{
		return (pos.x >= 0 && pos.x < n_cols - 1
			&& pos.y >= 0 && pos.y < n_rows - 1);
	}

	void drawLine(const Position<int>& pos, const char* shape, int width)
	{
		if (pos.y < 0 || pos.y >= n_rows) return; 

		int start = pos.x;
		int end = pos.x + width;

		if (end <= 0 || start >= n_cols) return;
		
		if (start < 0) start = 0;		
		if (end >= n_cols) end = n_cols - 1;

		if (start >= end) return;

		int offset = pos2offset(start, pos.y, n_cols);
		for (int w = 0; w < (end-start); w++)
		{
			if (shape[start-pos.x + w] != ' ')
				lines[offset + w] = shape[start-pos.x + w];
		}
	}

	void draw(const Position<int>& pos, const char* shape, const Dimension& size)
	{
		for (int h = 0; h < size.y; h++)
			drawLine(pos + Position<int>{ 0, h }, &shape[size.x * h], size.x);
	}

	void render()
	{
		Borland::GotoXY(0, 0);
		for (int i = 0; i < n_rows; i++)
			lines[i * n_cols + n_cols - 1] = '\n';
		lines[n_rows * n_cols] = '\0';
		printf("%s", lines);
		Sleep(10);
	}

	

};

