#include <iostream>
#include<string>
#include"GameObject.h"
#include"Screen.h"
#include"Utils.h"
using namespace std;


int pos2offset(int x, int y, int n_cols)
{
	return y * n_cols + x;
}

int main()
{
	const int n_cols = 6;
	const int n_rows = 6;

	GameObject player('>', 3, 3);

	Screen screen(30, 30);
	Position pos = player.getPos();

	int offset = pos2offset(pos.x, pos.y, n_cols);

	/* 2차원 배열 방법
	char lines[5][6];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			lines[i][j] = 'X';
		}
		lines[i][5] = '\0';
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", lines[i]);
	}
	*/

	char lines[5 * n_cols+1];

	while (1)
	{
		//(x,y) -> y * n_cols + x;
		

		screen.clear();

		screen.draw(player.getPos(), player.getShape());

		screen.render();
		

		lines[offset] = player.getShape();


		Borland::GotoXY(0, 0);
		printf("%s", lines);
		char key;
		cin >> key;

		printf("\n key is %c %d\n", key, key);

		//입력에 따라 플레이어 이동
		switch (key)
		{
		case 'w':
			pos.y--;
			break;
		case 'a':
			pos.x--;
			break;
		case 's':
			pos.y++;
			break;
		case 'd':
			pos.x++;
			break;
		}

		//if (pos == player.getPos()) continue;

		player.setPos(pos);
		
	}
	return 0;
	
}

