#pragma once
#include "GameObject.h"
#include "Screen.h"


class Player : public GameObject
{
public:
	Player(int x, int y) : GameObject('>', x, y){}

	void processInput(Screen& screen , int mineNum)
	{
		char key;

		cin >> key;

		Borland::GotoXY(0, 21);

		Position pos = getPos();

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
		case 'e':
			check(screen);
			break;
		case 'f':
			drawFlag(screen, mineNum);
			break;
		}

		setPos(pos);

	}

	//Ä­ Á¤º¸ È®ÀÎÇÏ´Â ÇÔ¼ö
	void check(Screen & screen)
	{

		Position pos = getPos();	

		char mineNum = screen.table2Lines(pos);

		if (mineNum >= '*' && mineNum <= '/')
		{
			mineNum = '*';
			screen.draw(pos, mineNum);
			cout << endl;
			cout << "Mine!" << endl;
			exit(0);
		}

		if (mineNum == '0')
		{

			screen.checkAround(pos.x, pos.y);

		}
		screen.draw(pos, mineNum);
	}


	//±ê¹ß ²È´Â ÇÔ¼ö
	void drawFlag(Screen& screen, int &Num)
	{
		Position pos = getPos();
		screen.draw(pos, 'F');

		static int mineNum = Num;
		static int flagNum = Num;

		flagNum--;

		cout << "flag: " << flagNum << endl;

		if (screen.table2Lines(pos) == '*')
		{
			mineNum--;
			screen.checkFlag(pos);
			cout << "mine: " << mineNum << endl;
		}

		if (mineNum == 0)
		{
			cout << "You Win!!" << endl;
			exit(0);
		}
		else if(flagNum == 0 && mineNum > 0)
		{
			cout << "No more flag" << endl;
			exit(0);
		}


	}

};


