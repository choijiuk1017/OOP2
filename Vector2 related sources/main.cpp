
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include "GameObject.h"
#include "Vector2.h"
#include "Utils.h"
#include "Screen.h"
#include "InputSystem.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class Student;

template<typename T>
bool isMultipleOfFive(const T& s)
{
	return s % 5 == 0;
}


class Student
{
	string name;
	int age;

public:
	Student(const string& name, int age) : name(name), age(age) {
		cout << "Student constructor" << endl;
	}

	Student(const Student& other) : name(other.name), age(other.age) {
		cout << "Student copy constructor" << endl;
	};

	~Student()
	{
		cout << "Student destructor" << endl;
	}

	friend ostream& operator<<(ostream& os, const Student& s);

	bool isMultipleOfThree() const { return this->age % 3 == 0;  }

	static bool isMultipleOfThree(const Student& student) { return student.age % 3 == 0; }
};


ostream& operator<<(ostream& os, const Student& s)
{
	os << "(name: " << s.name << ", age: " << s.age << ")";
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& container)
{
	for (auto& item: container) cout << item << endl;
	
	return os;
}

void increaseIntsBy1(vector<int>& vec)
{
	for (auto it = vec.begin();
		it != vec.end();
		it++
		)
	{
		auto& item = *it;
		item++;
	}
}


int main()
{
	Vector2<int> pos, pos1;
	Vector2<float> fPos;

	pos.set(10, 20);
	
	Vector2<int> pos2(30, 40);
	Vector2<int> pos3;

	
	pos3 = pos2;
	Vector2<int> pos4;
	pos = pos4 = pos3;

	
	pos = pos3 + pos2;
	pos = pos3 - pos2;

	int scale = 3;
	Vector2<int> newPos = pos1 + pos2 * scale;

	
	float div = 3;
	pos = pos3 / 3;

	Vector2<int> pos5 = scale * (pos1 + pos2);
	
	pos5.reset();
	pos3 = pos5 = 10;

	
	pos5 = Vector2<int>::zero;
	pos5 = Vector2<int>::one;

	fPos = Vector2<float>::one;

	cout << "fPos is " << fPos << endl;

	fPos = Vector2<float>::zero;

	cout << "fPos is " << fPos << endl;
	
	cout << pos5;

	cin >> pos5;

	cout << "pos5 after cin >> pos5 is " << pos5 << endl;
	double sz = pos5.magnitude(); // sqrt(x*x + y*y)

	double sqredSize = pos5.sqrMagnitude();  // x* x + y * y
	Vector2<double> dPos = pos;

	cout << "dPos is " << dPos << endl;

	dPos = dPos + Vector2<double>{ 12.5, 5415.6 };

	cout << "adding {12.5, 5415.6} " << dPos << endl;

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