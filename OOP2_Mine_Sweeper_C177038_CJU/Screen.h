#pragma once
#include <iostream>
#include "Utils.h"

using namespace std;

class Screen
{
	char* lines; //#으로 가리는 배열
	char* table; //숫자를 담을 배열 생성
	char* screen; //화면에 출력할 배열
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
		table(new char[n_rows * n_cols + 1]),//lines와 같은 크기로 초기화
		screen(new char[n_rows * n_cols + 1])
	{
		Borland::Initialize();
		clear();//line을 #으로 설정

		clearTable(); //table을 0으로 설정
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

	//lines의 정보를 screen으로 복사
	void lines2Screen()
	{
		memcpy(screen, lines, n_rows * n_cols+1);	
	}
	
	//screen을 출력하는 함수
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

	//screen에 그려주는 함수, 플레이어를 lines가 아닌 screen에 그림으로써 lines 정보는 따로 불러옴
	void drawScreen(const Position & pos, char shape)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);

		screen[offset] = shape;
	}
	
	//table에그려주는 함수, 지뢰의 위치 표기 용도
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

	//Table을 그려주는 함수, 확인용
	void renderTable()
	{
		cout << endl;
		cout << "table 확인" << endl;
 		printf("%s", table);
	}

	//table을 0으로 초기화하는 함수
	void clearTable()
	{
		memset(table, '0', n_rows * n_cols);

		for (int i = 0; i < n_rows; i++)
		{
			table[i * n_cols + n_rows] = '\n';
		}
		table[n_rows * n_cols] = '\0';
	}
	
	//0일때 주변을 탐색하는 함수
	void checkAround(int x, int y)
	{
		int offset = pos2offset(x, y, n_cols);

		checkLeft(x, y);
		checkRight(x, y);
		checkBottom(x, y);

		//왼쪽 위 탐사
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

		//위 탐사
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


		//오른쪽 위 탐사
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


	//아래쪽 탐사
	void checkBottom(int x, int y)
	{
		int offset = pos2offset(x, y, n_cols);

		//왼쪽 아래 탐사
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

		//아래 탐사
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


		//오른쪽 아래 탐사
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

	//왼쪽 탐사
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

	//오른쪽 탐사
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

	//깃발인 부분 지뢰인지 확인, 확인용
	void checkFlag(const Position& pos)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);
		if (table[offset] == '*')
		{
			table[offset] = 'F';
		}
	}

	//해당 위치의 table 정보를 주는 함수
	char table2Lines(const Position & pos)
	{
		int offset = pos2offset(pos.x, pos.y, n_cols);
		char shape = table[offset];

		return shape;
	}

	//지뢰 근처에 숫자 표기
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
		
		//지뢰가 변경될 수 있으므로 *로 표기 되게 유지
		for (int i = 0; i < n_rows * n_cols; i++)
		{
			if (table[i] >= '*' && table[i] <= '/')
			{
				table[i] = '*';
			}
		}
	}
};

