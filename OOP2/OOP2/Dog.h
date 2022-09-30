#pragma once
#include "Pet.h"
class Dog : public Pet
{
private:
	unsigned int durationRattling;
public:
	Dog(const string& name, int age, unsigned int durationRattling = 1) : Pet(name, age), durationRattling (10)
	{
		cout << "Dog constructor" << endl;
	}
	virtual ~Dog() 
	{
		cout << "Dog destructor" << endl;
	}

	void bark()
	{
		cout << "bark" << endl;
	}

	void sleep()
	{
		cout << "rattling" << endl;

		/*
		Pet* parent = static_cast<Pet*>(this);
		parent->sleep();
		*/ 
		//������ ���

		Pet::sleep(); //������ ������
	}

};

