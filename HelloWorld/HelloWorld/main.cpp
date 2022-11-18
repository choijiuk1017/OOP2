
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include "GameObject.h"
#include "Utils.h"
#include "Screen.h"
#include "InputSystem.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main()
{
	//vector<int> ints(10); //10 만큼의 배열 공간 생성, 10 대입 아님
	// vector 사용 시 배열 공간의 크기는 유동적으로 변경 가능
	
	/*ints.push_back(20);
	ints.push_back(30);
	ints.push_back(50);
	ints.push_back(1);
	ints.push_back(24);*/

	//vector<int> ints = { 20, 30, 50, 1, 24 };

	vector<int> ints{ 20, 30, 50, 1, 24 };

	for (/*vector<int>::const_iterator*/ auto it = ints.cbegin(); it != ints.cend(); it++)
	{
		//cbegin 읽기 전용, begin 고치기 가능
		auto item = *it;

		cout << "item = " << item << endl;
	}
	
	for (/*vector<int>::iterator*/ auto it = ints.begin(); it != ints.end(); it++)
	{
		//cbegin 읽기 전용, begin 고치기 가능
		auto& item = *it;

		item++;

		cout << "item = " << item << endl;
	}

	//C#의 foreach문과 동일, ranged for문
	for (auto item : ints)
	{
		item++;
		cout << "item = " << item << endl;
	}

	for (auto item : ints)
	{
		cout << "item = " << item << endl;
	}
	//item이 바뀌긴 하나 원본에게 영향을 끼치진 않음

	for (auto& item : ints)
	{
		item++;
		cout << "item = " << item << endl;
	}

	for (auto item : ints)
	{
		cout << "item = " << item << endl;
	}
	//item도 바뀌고 원본도 바뀜

	//장점: 깔끔함, 인덱스 오류가 발생할 일 없음
	//단점: 새로운 배열 추가, 삭제 불가능

	return 0;


	Screen screen(30, 81);
	InputSystem input;

	GameObject::Initialize(screen, input);

	while (true)
	{
		screen.clear();
		input.readEveryFrame();

		GameObject::Update();
		GameObject::DestoryDisabledObjects();
		GameObject::Draw();
		
		screen.render();
	}

	GameObject::Deinitialize();

	
	return 0;
}