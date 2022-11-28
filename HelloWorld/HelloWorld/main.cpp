
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
		cout << "Student copy constructor" << endl;

	}


	Student(const Student& other) : name(other.name), age(other.age)
	{
		cout << "Student copy constructor" << endl;

	};

	~Student()
	{
		cout << "Student destructer" << endl;
	}
	//전역 함수임, 멤버 함수 아님0
	//전역 함수의 내용을 클래스 안에 구현해 놓은 것
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
ostream & operator << (ostream & os, const vector<T>& container)
{
	for (auto &item : container)
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
	//vector<int> ints(10); //10 만큼의 배열 공간 생성, 10 대입 아님
	// vector 사용 시 배열 공간의 크기는 유동적으로 변경 가능

	vector<Student> students;

	students.push_back({ "Beomjoo Seo", 18 });
	students.push_back({ "Bae, Byungcheol", 24 });
	students.push_back({ "Shin-Jin, Kang", 21 });
	students.push_back({ "Yejin Kim", 17 });
	students.push_back({ "Kim HyeYong", 22 });

	cout << students << endl;

	cout << endl << "find" << endl;

	//erase - remove idiom
	//객체들 조건에 따라 삭제할 때 사용
	students.erase(
		remove_if(students.begin(),
			students.end(), 
			[](auto& student)
			{
				return student.isMultipleOfThree(); //함수가 자동완성이 왜 안돼 시발 거

			}
		), students.end());

	cout << students << endl;



	for (auto it = students.begin(); it != students.end();)
	{
		auto& student = *it;

		if (student.isMultipleOfThree())
		{
			it = students.erase(it); //erase 를 쓸때는 지우고 재해석 필요
		}
		else
		{
			it++;
		}
	}

	cout << students << endl;

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