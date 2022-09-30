#pragma once
#include<iostream>
#include<string>

using namespace std;

class Pet
{
private:
	string name;
	int age;

public:
	Pet(const string& name = "unnamed", int age = 0) : name(name), age(age)
	{
		cout << "Pet constructor" << endl;
	}
	virtual ~Pet() 
	{
		cout << "Pet destructor" << endl;
	}

	string getName() { return name; }
	int getAge() { return age; }

	virtual void sleep()
	{
		cout << "sleep" << endl;
	}
	void eat()
	{
		cout << "eat" << endl;
	}
}; 


