
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
	//vector<int> ints(10); //10 ��ŭ�� �迭 ���� ����, 10 ���� �ƴ�
	// vector ��� �� �迭 ������ ũ��� ���������� ���� ����
	
	/*ints.push_back(20);
	ints.push_back(30);
	ints.push_back(50);
	ints.push_back(1);
	ints.push_back(24);*/

	//vector<int> ints = { 20, 30, 50, 1, 24 };

	vector<int> ints{ 20, 30, 50, 1, 24 };

	for (/*vector<int>::const_iterator*/ auto it = ints.cbegin(); it != ints.cend(); it++)
	{
		//cbegin �б� ����, begin ��ġ�� ����
		auto item = *it;

		cout << "item = " << item << endl;
	}
	
	for (/*vector<int>::iterator*/ auto it = ints.begin(); it != ints.end(); it++)
	{
		//cbegin �б� ����, begin ��ġ�� ����
		auto& item = *it;

		item++;

		cout << "item = " << item << endl;
	}

	//C#�� foreach���� ����, ranged for��
	for (auto item : ints)
	{
		item++;
		cout << "item = " << item << endl;
	}

	for (auto item : ints)
	{
		cout << "item = " << item << endl;
	}
	//item�� �ٲ�� �ϳ� �������� ������ ��ġ�� ����

	for (auto& item : ints)
	{
		item++;
		cout << "item = " << item << endl;
	}

	for (auto item : ints)
	{
		cout << "item = " << item << endl;
	}
	//item�� �ٲ�� ������ �ٲ�

	//����: �����, �ε��� ������ �߻��� �� ����
	//����: ���ο� �迭 �߰�, ���� �Ұ���

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