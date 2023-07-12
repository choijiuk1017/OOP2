#include "Player.h"

void Player::check(const Position& pos)
{
	Borland::GotoXY(0, 13);

	char mineNum = screen.table2Lines(pos);

	if (mineNum >= '*' && mineNum <= '/')
	{
		mineNum = '*';
		screen.draw(pos, mineNum);
		printf("Mine!");
		exit(0);
	}

	if (mineNum == '0')
	{
		screen.checkAround(pos.x, pos.y);
	}

	screen.draw(pos, mineNum);
}

void Player::drawFlag(int& Num, const Position& pos)
{
	Borland::GotoXY(0, 14);

	screen.draw(pos, 'F');

	static int mineNum = Num;
	static int flagNum = Num;

	flagNum--;

	printf("flag: %d\n", flagNum);

	if (screen.table2Lines(pos) == '*')
	{
		mineNum--;
		screen.checkFlag(pos);
		printf("mine: %d\n", mineNum);
	}

	if (mineNum == 0)
	{
		printf("You Win!!\n");
		exit(0);
	}
	else if (flagNum == 0 && mineNum > 0)
	{
		printf("No more flag\n");
		exit(0);
	}
}

void Player::printInformation()
{
	Borland::GotoXY(0, 16);

	printf("W, A, S, D: 키보드 이동\n");
	printf("E: 해당 위치 확인\n");
	printf("F: 깃발 꽂기\n");
	printf("좌클릭: 확인\n");
	printf("우클릭: 깃발\n");
}
