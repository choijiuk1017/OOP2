#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;

class Screen
{
	char* lines; //#���� ������ �迭
	char* table; //���ڸ� ���� �迭 ����
	char* screen; //ȭ�鿡 ����� �迭
	int n_rows;
	int n_cols;



	int pos2offset(int x, int y, int n_cols)
	{
		return y * n_cols + x;
	}

public:
	Screen(int n_rows = 10, int n_cols = 11)
		: n_rows(n_rows), n_cols(n_cols),
		lines(new char[n_rows * n_cols + 1]),
		table(new char[n_rows * n_cols + 1]),//lines�� ���� ũ��� �ʱ�ȭ
		screen(new char[n_rows * n_cols + 1])
	{
		Borland::Initialize();
		clear();//line�� #���� ����

		clearTable(); //table�� 0���� ����
		render();
	}

	virtual ~Screen() { delete[] lines;}

	void clear()
	{
		memset(lines, '#', n_rows * n_cols);
		for (int i = 0; i < n_rows; i++)
			lines[i * n_cols + n_rows] = '\n';
		lines[n_rows * n_cols] = '\0';
	}

	//lines�� ������ screen���� ����
	void lines2Screen()
	{
		memcpy(screen, lines, n_rows * n_cols+1);	
	}
	
	//screen�� ����ϴ� �Լ�
	void rendScreen()
	{
		Borland::GotoXY(0, 0);
		printf("%s", screen);
	}

	void draw(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);

		lines[offset] = shape;
	}

	//screen�� �׷��ִ� �Լ�, �÷��̾ lines�� �ƴ� screen�� �׸����ν� lines ������ ���� �ҷ���
	void drawScreen(const Position & pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);

		screen[offset] = shape;
	}
	
	//table���׷��ִ� �Լ�, ������ ��ġ ǥ�� �뵵
	void drawTable(const Position& pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);

		table[offset] = shape;
	}

	void render()
	{
		Borland::GotoXY(0, 0);
		printf("%s", lines);
	}

	//Table�� �׷��ִ� �Լ�, Ȯ�ο�
	void renderTable()
	{
		cout << endl;
		cout << "table Ȯ��" << endl;
 		printf("%s", table);
	}

	//table�� 0���� �ʱ�ȭ�ϴ� �Լ�
	void clearTable()
	{
		memset(table, '0', n_rows * n_cols);

		for (int i = 0; i < n_rows; i++)
		{
			table[i * n_cols + n_rows] = '\n';
		}
		table[n_rows * n_cols] = '\0';
	}
	
	//0�϶� �ֺ��� Ž���ϴ� �Լ�
	void checkAround(int x, int y)
	{
		int offset = pos2offset(x, y, n_cols);

		checkLeft(x, y);
		checkRight(x, y);
		checkBottom(x, y);

		//���� �� Ž��
		if (table[offset - 12] != '\n' && table[offset - 12] != '\0')
		{
			if (table[offset - 12] == '0')
			{
				lines[offset - 12] = table[offset - 12];
				checkAround(x - 1, y + 1);
			}
			else if (table[offset - 12] >= '1')
			{
				lines[offset - 12] = table[offset - 12];
				return;
			}
			else
			{
				return;
			}
		}

		//�� Ž��
		if (table[offset - 11] != '\n' && table[offset - 11] != '\0')
		{
			if (table[offset - 11] == '0')
			{
				lines[offset - 11] = table[offset - 11];
				checkAround(x, y + 1);
			}
			else if (table[offset - 11] >= '1')
			{
				lines[offset - 11] = table[offset - 11];
				return;
			}
			else
			{
				return;
			}
		}


		//������ �� Ž��
		if (table[offset - 10] != '\n' && table[offset - 10] != '\0')
		{
			if (table[offset - 10] == '0')
			{
				lines[offset - 10] = table[offset - 10];
				checkAround(x + 1, y + 1);
			}
			else if (table[offset - 10] >= '1')
			{
				lines[offset - 10] = table[offset - 10];
				return;
			}
			else
			{
				return;
			}
		}
	}


	//�Ʒ��� Ž��
	void checkBottom(int x, int y)
	{
		int offset = pos2offset(x, y, n_cols);

		//���� �Ʒ� Ž��
		if (table[offset + 10] != '\n' && table[offset + 10] != '\0')
		{

			if (table[offset + 10] == '0')
			{
				lines[offset + 10] = table[offset + 10];
				checkBottom(x - 1, y - 1);
			}
			else if (table[offset + 10] >= '1')
			{
				lines[offset + 10] = table[offset + 10];
				return;
			}
			else
			{
				return;
			}
		}

		//�Ʒ� Ž��
		if (table[offset + 11] != '\n' && table[offset + 11] != '\0')
		{

			if (table[offset + 11] == '0')
			{
				lines[offset + 11] = table[offset + 11];
				checkBottom(x, y - 1);
			}
			else if (table[offset + 11] >= '1')
			{
				lines[offset + 11] = table[offset + 11];
				return;
			}
			else
			{
				return;
			}
		}


		//������ �Ʒ� Ž��
		if (table[offset + 12] != '\n' && table[offset + 12] != '\0')
		{

			if (table[offset + 12] == '0')
			{
				lines[offset + 12] = table[offset + 12];
				checkBottom(x + 1, y - 1);
			}
			else if (table[offset + 12] >= '1')
			{
				lines[offset + 12] = table[offset + 12];
				return;
			}
			else
			{
				return;
			}
		}

	}

	//���� Ž��
	void checkLeft(int x, int y)
	{
		int offset = pos2offset(x, y, n_cols);


		if (table[offset - 1] != '\n' && table[offset - 1] != '\0')
		{

			if (table[offset - 1] == '0')
			{
				lines[offset - 1] = table[offset - 1];
				checkLeft(x - 1, y);
			}
			else if (table[offset - 1] >= '1')
			{
				lines[offset - 1] = table[offset - 1];
				return;
			}
			else
			{
				return;
			}
		}
	}

	//������ Ž��
	void checkRight(int x, int y)
	{
		int offset = pos2offset(x, y, n_cols);

		if (table[offset + 1] != '\n' && table[offset + 1] != '\0')
		{
			if (table[offset + 1] == '0')
			{	
				lines[offset + 1] = table[offset + 1];
				checkRight(x + 1, y);
			}
			else if (table[offset + 1] >= '1')
			{
				lines[offset + 1] = table[offset + 1];
				return;
			}
			else
			{
				return;
			}
		}

	}

	//����� �κ� �������� Ȯ��, Ȯ�ο�
	void checkFlag(const Position& pos)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);
		if (table[offset] == '*')
		{
			table[offset] = 'F';
		}
	}

	//�ش� ��ġ�� table ������ �ִ� �Լ�
	char table2Lines(const Position & pos)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);
		char shape = table[offset];

		return shape;
	}

	//���� ��ó�� ���� ǥ��
	void setTable(const Position& pos)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);

		if (offset > 10 && table[offset - 1] == '\n')
		{
			table[offset + 1]++;
			table[offset - 10]++;
			table[offset - 11]++;
			table[offset + 11]++;
			table[offset + 12]++;
		}
		else if (offset > 10 && table[offset + 1] == '\n')
		{
			table[offset - 12]++;
			table[offset + 11]++;
			table[offset - 11]++;
			table[offset + 10]++;
			table[offset - 1]++;
		}
		else if (offset < 10)
		{
			if (offset == 0)
			{
				table[offset + 11]++;
				table[offset + 1]++;
				table[offset + 12]++;
			}
			else
			{
				table[offset - 1]++;
				table[offset + 1]++;
				table[offset + 10]++;
				table[offset + 11]++;
				table[offset + 12]++;
			}
		}
		else
		{
			table[offset - 12]++;
			table[offset - 11]++;
			table[offset - 10]++;
			table[offset - 1]++;
			table[offset + 1]++;
			table[offset + 10]++;
			table[offset + 11]++;
			table[offset + 12]++;
		}
		
		//���ڰ� ����� �� �����Ƿ� *�� ǥ�� �ǰ� ����
		for (int i = 0; i < n_rows * n_cols; i++)
		{
			if (table[i] >= '*' && table[i] <= '/')
			{
				table[i] = '*';
			}
		}
	}
};

