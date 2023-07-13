#pragma once
#include "ScreenTable.h"
#include "NumTable.h"
class MainTable : public ScreenTable
{
	int rows;
	int cols;

	char* mainTable; //player 전용 table
	char* hideTable; //#으로 가리는 table

	NumTable& numTable;
public:
	MainTable(int rows, int cols, NumTable & numTable) 
		: ScreenTable(rows, cols),
		rows(rows), cols(cols),
		mainTable(new char[rows * cols + 1]),
		hideTable(new char[rows * cols + 1]),
		numTable(numTable)
	{
		Clear();

		Render();
	}

	virtual void Clear()
	{
		memset(mainTable, '#', rows * cols);
		for (int i = 0; i < rows; i++)
			mainTable[i * cols + rows] = '\n';
		mainTable[rows * cols] = '\0';
	}

	virtual void Draw(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, cols);

		hideTable[offset] = shape;
	}

	//player 그리기 전용 함수
	void DrawMain(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, cols);

		mainTable[offset] = shape;
	}

	//hideTable의 정보를 mainTable로 옮김
	void Hide2Main()
	{
		memcpy(mainTable, hideTable, rows * cols + 1);
	}

	virtual void Render()
	{
		Borland::GotoXY(0, 0);
		printf("%s", hideTable);
	}

	

};

