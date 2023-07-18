#include <iostream>
#include <string>
#include <time.h>
#include "GameObject.h"
#include "Utils.h"
#include "MainTable.h"
#include "numTable.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	static int randomNum = 10 + rand() % 11; //지뢰의 수 10이상 20 이하

	NumTable numTable{10, 11};

	MainTable mainTable{ 10, 11, numTable};

	InputSystem input;

	Player player{ 0, 0 ,mainTable, numTable, input};

	Enemy* enemy[20] = {}; //생성될 수 있는 지뢰가 최대 20개이기 때문에 20개 크기의 배열 사용

	

	//지뢰를 중복 없이 생성
	for (int i = 0; i < randomNum; i++)
	{
		enemy[i] = new Enemy();
		for (int j = 0; j < i; j++)
		{
			//x, y 좌표가 똑같으면 다시 생성
			if (enemy[i]->getX() == enemy[j]->getX() && enemy[i]->getY() == enemy[j]->getY())
			{
				i--;
			}
		}
	}

	//지뢰 숫자만큼 생성
	for (int i = 0; i < randomNum; i++)
	{
		numTable.Draw(enemy[i]->getPos(), enemy[i]->getShape()); //table에 지뢰 생성

		numTable.SetTable(enemy[i]->getPos()); //지뢰 근처 숫자 생성
	}

	//게임 루프
	while (1)
	{

		mainTable.Hide2Main(); //lines의 정보를 계속해서 screen으로 복사

		player.draw();

		player.update(randomNum);

		mainTable.RenderMain();

		input.readEveryFrame();
		//screen.renderTable(); //확인용

		//player.printInformation();
	}

	//동적 생성한 enemy들을 NULL로 변환
	for (int i = 0; i < randomNum; i++)
	{
		enemy[i] = NULL;
	}

	return 0;
}

