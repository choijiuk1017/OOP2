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

	printf("W, A, S, D: Ű���� �̵�\n");
	printf("E: �ش� ��ġ Ȯ��\n");
	printf("F: ��� �ȱ�\n");
	printf("��Ŭ��: Ȯ��\n");
	printf("��Ŭ��: ���\n");
}
