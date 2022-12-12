#pragma once


class GameObject;

class Component
{
protected:
	GameObject* gameObject;

	friend GameObject;

public:
	Component(GameObject* gameObject);
	virtual ~Component();

	virtual void start() {}

	virtual void update() {}

	virtual void onDestory() {}
};

