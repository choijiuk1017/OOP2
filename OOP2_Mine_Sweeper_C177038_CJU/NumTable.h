#pragma once
#include "ScreenTable.h"
class NumTable :
    public ScreenTable
{
	friend class MainTable;

	int rows;
	int cols;

	char* numTable;

	
public:
	NumTable(int rows, int cols)
		: ScreenTable(rows, cols),
		rows(rows), cols(cols),
		numTable(new char[rows * cols + 1])
	{
		Clear();
	}


	//table 초기화 함수, 0으로 초기화
	virtual void Clear()
	{
		memset(numTable, '0', rows * cols);
		for (int i = 0; i < rows; i++)
			numTable[i * cols + rows] = '\n';
		numTable[rows * cols] = '\0';
	}

	//table에 그려주는 함수
	virtual void Draw(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, cols);

		numTable[offset] = shape;
	}

	//해당 위치의 정보 반환
	char CheckPos(int x, int y)
	{
		int offset = pos2offset(x, y, cols);

		char shape = numTable[offset];

		return shape;
	}

	//지뢰 근처에 숫자 표기
	void SetTable(const Position& pos)
	{
		int offset = pos2offset(pos.x, pos.y, cols);

		//지뢰 주변 칸은 전부 +1
		if (offset > 10 && numTable[offset - 1] == '\n')
		{
			numTable[offset + 1]++;
			numTable[offset - 10]++;
			numTable[offset - 11]++;
			numTable[offset + 11]++;
			numTable[offset + 12]++;
		}
		else if (offset > 10 && numTable[offset + 1] == '\n')
		{
			numTable[offset - 12]++;
			numTable[offset + 11]++;
			numTable[offset - 11]++;
			numTable[offset + 10]++;
			numTable[offset - 1]++;
		}
		else if (offset < 10)
		{
			if (offset == 0)
			{
				numTable[offset + 11]++;
				numTable[offset + 1]++;
				numTable[offset + 12]++;
			}
			else
			{
				numTable[offset - 1]++;
				numTable[offset + 1]++;
				numTable[offset + 10]++;
				numTable[offset + 11]++;
				numTable[offset + 12]++;
			}
		}
		else
		{
			numTable[offset - 11]++;
			numTable[offset - 10]++;
			numTable[offset - 1]++;
			numTable[offset + 1]++;
			numTable[offset + 10]++;
			numTable[offset + 11]++;
			numTable[offset + 12]++;
		}

		//지뢰가 변경될 수 있으므로 *로 표기 되게 유지
		for (int i = 0; i < rows * cols; i++)
		{
			if (numTable[i] >= '*' && numTable[i] <= '/')
			{
				numTable[i] = '*';
			}
		}
	}

	//깃발인 부분 지뢰인지 확인, 확인용
	void CheckFlag(const Position& pos)
	{
		int offset = pos2offset(pos.x, pos.y, cols);
		if (numTable[offset] == '*')
		{
			numTable[offset] = 'F';
		}
	}
};

