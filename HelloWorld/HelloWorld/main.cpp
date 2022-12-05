
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

	//깊은 복사 
	//move semantic 참고
	Student(const Student& other) : name(other.name), age(other.age)
	{
		cout << "Student copy constructor" << endl;

	};

	~Student()
	{
		cout << "Student destructer" << endl;
	}

	//전형저긴 getter 함수
	string getName() const //복사본을 전달, 원본 정보 절대로 보내지 말 것
	{
		return name;
	}
	//레퍼런스 변수를 리턴 값으로 설정하지 말 것

	bool equalName(const string& name) const
	{
		return this->name == name;
	}

	int getAge() const
	{
		return age;
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
	////vector<int> ints(10); //10 만큼의 배열 공간 생성, 10 대입 아님
	//// vector 사용 시 배열 공간의 크기는 유동적으로 변경 가능

	//vector<Student> students;

	//Student student{ "Kim Cheol Soo", 39 };

	//students.push_back(move(student)); //move semantic(성능 개선)

	//students.push_back(move(Student{ "Beomjoo Seo", 18 }));
	//students.push_back({ "Bae, Byungcheol", 24 });
	//students.push_back({ "Shin-Jin, Kang", 21 });
	//students.push_back({ "Yejin Kim", 17 });
	//students.push_back({ "Kim HyeYoung", 22 });

	//cout << students << endl;

	//cout << endl << "find" << endl;

	////원하는 객체 지우기
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


	//유니티의 GameObject obj == C++의 GameObject * obj 임
	vector<GameObject*> objs;

	objs.reserve(10); //공간 만들어주는 함수
	
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