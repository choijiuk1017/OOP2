#pragma once
#include "ScreenTable.h"
class NumTable :
    public ScreenTable
{
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

	virtual void Clear()
	{
		memset(numTable, '0', rows * cols);
		for (int i = 0; i < rows; i++)
			numTable[i * cols + rows] = '\n';
		numTable[rows * cols] = '\0';
	}

	virtual void Draw(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, cols);

		numTable[offset] = shape;
	}

	//�ش� ��ġ�� ���� ��ȯ
	char CheckPos(const Position& pos)
	{
		int offset = pos2offset(pos.x, pos.y, cols);

		char shape = numTable[offset];

		return shape;
	}

	//���� ��ó�� ���� ǥ��
	void setTable(const Position& pos)
	{
		int offset = pos2offset(pos.x, pos.y, cols);

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

		//���ڰ� ����� �� �����Ƿ� *�� ǥ�� �ǰ� ����
		for (int i = 0; i < rows * cols; i++)
		{
			if (numTable[i] >= '*' && numTable[i] <= '/')
			{
				numTable[i] = '*';
			}
		}
	}
};

