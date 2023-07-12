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

	printf("W, A, S, D: Ű���� �̵�\n");
	printf("E: �ش� ��ġ Ȯ��\n");
	printf("F: ��� �ȱ�\n");
	printf("��Ŭ��: Ȯ��\n");
	printf("��Ŭ��: ���\n");
}
