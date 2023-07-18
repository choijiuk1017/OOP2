#pragma once
#include "ScreenTable.h"
#include "NumTable.h"
class MainTable : public ScreenTable
{
	int rows;
	int cols;

	char* mainTable; //player ���� table
	char* hideTable; //#���� ������ table

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

	//table �ʱ�ȭ �Լ�, #���� �ʱ�ȭ
	virtual void Clear()
	{
		memset(hideTable, '#', rows * cols);
		for (int i = 0; i < rows; i++)
			hideTable[i * cols + rows] = '\n';
		hideTable[rows * cols] = '\0';
	}

	//table�� �׷��ִ� �Լ�
	virtual void Draw(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, cols);

		hideTable[offset] = shape;
	}

	//player �׸��� ���� �Լ�
	void DrawMain(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, cols);

		mainTable[offset] = shape;
	}

	//hideTable�� ������ mainTable�� �ű�
	void Hide2Main()
	{
		memcpy(mainTable, hideTable, rows * cols + 1);
	}

	//��� �Լ�
	virtual void Render()
	{
		Borland::GotoXY(0, 0);
		printf("%s", hideTable);
	}

	void RenderMain()
	{
		Borland::GotoXY(0, 0);
		printf("%s", mainTable);
	}

	void CheckAround(int x, int y)
	{
		int offset = pos2offset(x, y, cols);

		if (numTable.CheckPos(x, y) == '\0' || numTable.CheckPos(x, y) == '\n' || numTable.CheckPos(x, y) != '0')
		{
			return;
		}

		hideTable[offset] = '0';

		//CheckAround(x - 1, y - 1);
		CheckAround(x - 1, y);
		//CheckAround(x - 1, y + 1);
		CheckAround(x, y - 1);
		CheckAround(x, y + 1);
		//CheckAround(x + 1, y - 1);
		CheckAround(x + 1, y);
		//CheckAround(x + 1, y + 1);
	}
		
	

	

};

