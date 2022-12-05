
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
template <typename T>
bool isMultipleOfFive(const T& s)
{
	return s.age % 5 = 0;
}

template <typename T>
bool isMultipleOfThree(const T& s)
{
	return s.age % 3 = 0;
}


class Student
{
	string name;
	int age;

public:
	Student(const string& name, int age) : name(name), age(age)
	{
		cout << "Student constructor" << endl;

	}

	//���� ���� 
	//move semantic ����
	Student(const Student& other) : name(other.name), age(other.age)
	{
		cout << "Student copy constructor" << endl;

	};

	~Student()
	{
		cout << "Student destructer" << endl;
	}

	//�������� getter �Լ�
	string getName() const //���纻�� ����, ���� ���� ����� ������ �� ��
	{
		return name;
	}
	//���۷��� ������ ���� ������ �������� �� ��

	bool equalName(const string& name) const
	{
		return this->name == name;
	}

	int getAge() const
	{
		return age;
	}


	//���� �Լ���, ��� �Լ� �ƴ�0
	//���� �Լ��� ������ Ŭ���� �ȿ� ������ ���� ��
	friend ostream& operator << (ostream& os, const Student& s);
	/*{
		os << "name =" << s.name << ", age = " << s.age << endl;
		return os;
	}*/

	bool isMultipleOfThree()
	{
		return this->age % 3 == 0;
	}

	static bool isMultipleOfThree(const Student& student) { return student.age % 3 == 0; }

};


ostream& operator << (ostream& os, const Student& s)
{
	os << "name =" << s.name << ", age = " << s.age << endl;
	return os;
}


template<typename T>
ostream& operator << (ostream& os, const vector<T>& container)
{
	for (auto& item : container)
	{
		//data[i].print();
		cout << item << endl;
		//(cout.operator <<(data[i])).operator(endl);
		//operator<<(operator << (cout, data[i]), endl);
	}
	return os;
}

int main()
{
	////vector<int> ints(10); //10 ��ŭ�� �迭 ���� ����, 10 ���� �ƴ�
	//// vector ��� �� �迭 ������ ũ��� ���������� ���� ����

	//vector<Student> students;

	//Student student{ "Kim Cheol Soo", 39 };

	//students.push_back(move(student)); //move semantic(���� ����)

	//students.push_back(move(Student{ "Beomjoo Seo", 18 }));
	//students.push_back({ "Bae, Byungcheol", 24 });
	//students.push_back({ "Shin-Jin, Kang", 21 });
	//students.push_back({ "Yejin Kim", 17 });
	//students.push_back({ "Kim HyeYoung", 22 });

	//cout << students << endl;

	//cout << endl << "find" << endl;

	////���ϴ� ��ü �����
	////1. find -> erase
	///*
	//auto pos = find_if(students.begin(), students.end(),
	//	[](Student& student) {return student.getName() == "Kim HyeYoung"; }
	//);
	//if (pos != students.end())
	//{
	//	students.erase(pos);
	//}

	//cout << students << endl;
	//*/
	////2. erase - remove idiom
	///*
	//students.erase(
	//	remove_if(
	//		students.begin(),
	//		students.end(),
	//		[](auto& student)
	//		{ return student.equalName("Bae, Byungcheol"); }
	//	),
	//	students.end()
	//);

	//cout << students << endl;
	//*/

	//sort(students.begin(), students.end(),
	//	[](auto& a, auto b) {return a.getName() > b.getName(); });

	//cout << students << endl;

	//return 0;

	Screen screen(30, 81);
	InputSystem input;


	//����Ƽ�� GameObject obj == C++�� GameObject * obj ��
	vector<GameObject*> objs;

	objs.reserve(10); //���� ������ִ� �Լ�
	
	objs.push_back(new Player("\xB2\xB2\xB2\xB2 \xB2\xB2 \xB2", { 40, 10 }, screen, input, { 3, 3 }));
	objs.push_back(new Enemy("\xB0\xB0", { 10, 5 }, screen, input, { 2, 1 }));
	objs.push_back(new Enemy("\xB0\xB0", { 5, 7 }, screen, input, { 2, 1 }));



	while (true)
	{
		screen.clear();
		input.readEveryFrame();

		for (auto& obj : objs)
		{
			obj->update();
		}
		for (auto& obj : objs)
		{
			obj->draw();
		}

		screen.render();
	}

	GameObject::Deinitialize();


	return 0;
}