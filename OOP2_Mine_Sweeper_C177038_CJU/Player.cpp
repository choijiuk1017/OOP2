#include "Player.h"

void Player::check(const Position& pos)
{
	Borland::GotoXY(0, 13);

	char mineNum = numTable.CheckPos(pos.x, pos.y);

	if (mineNum >= '*' && mineNum <= '/')
	{
		mineNum = '*';
		mainTable.Draw(pos, mineNum);
		printf("Mine!");
		exit(0);
	}

	if (mineNum == '0')
	{
		mainTable.CheckAround(pos.x, pos.y);
	}

	mainTable.Draw(pos, mineNum);
}

void Player::drawFlag(int& Num, const Position& pos)
{
	Borland::GotoXY(0, 14);

	mainTable.Draw(pos, 'F');

	static int mineNum = Num;
	static int flagNum = Num;

	flagNum--;

	printf("flag: %d\n", flagNum);

	if (numTable.CheckPos(pos.x ,pos.y) == '*')
	{
		mineNum--;
		numTable.CheckFlag(pos);
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
