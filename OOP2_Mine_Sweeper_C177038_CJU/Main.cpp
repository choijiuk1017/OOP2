#include <iostream>
#include <string>
#include <time.h>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	srand((unsigned int)time(NULL));

	static int randomNum = 10 + rand() % 11; //지뢰의 수 10이상 20 이하

	Player player{ 0, 0 };

	Enemy* enemy[20] = {}; //생성될 수 있는 지뢰가 최대 20개이기 때문에 20개 크기의 배열 사용

	Screen screen;

	//지뢰를 중복 없이 생성
	for (int i = 0; i < randomNum; i++)
	{
		enemy[i] = new Enemy;
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
		screen.drawTable(enemy[i]->getPos(), enemy[i]->getShape()); //table에 지뢰 생성

		screen.setTable(enemy[i]->getPos()); //지뢰 근처 숫자 생성
	}
	cout << endl;
	cout << "w: 위쪽 이동" << endl;
	cout << "a: 왼쪽 이동" << endl;
	cout << "s: 아래쪽 이동" << endl;
	cout << "d: 오른쪽 이동" << endl;
	cout << "e: 해당 위치 확인" << endl;
	cout << "f: 깃발 꽂기" << endl;

	//게임 루프
	while (1)
	{

		screen.lines2Screen(); //lines의 정보를 계속해서 screen으로 복사

		screen.drawScreen(player.getPos(), player.getShape()); //플레이어를 screen에 그림

		player.processInput(screen, randomNum); 

		screen.rendScreen();

		//screen.renderTable(); //확인용

	}

	//동적 생성한 enemy들을 NULL로 변환
	for (int i = 0; i < randomNum; i++)
	{
		enemy[i] = NULL;
	}

	return 0;
}

