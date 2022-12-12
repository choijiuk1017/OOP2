#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "Utils.h"
#include "Screen.h"
#include "InputSystem.h"
#include "Component.h"

using namespace std;

class GameObject
{
	Position<float>	pos;
	char*		shape;
	Dimension	dim;
	bool		enabled;

protected:
	InputSystem& input;
	Screen& screen;

	vector<unique_ptr<Component>> components;

	template<class T>
	void addComponent(T* comp)
	{
		auto it = find_if(components.cbegin(), components.cend(), [](auto& item) {
			Component* obj = item.get();
			return dynamic_cast<T*>(obj) != nullptr;
		});
		if (it == components.cend()) components.push_back(move(unique_ptr<T>(comp)));
	}

	template<class T>
	T* getComponent()
	{
		auto it = find_if(components.begin(), components.end(), [](auto& item) {
			Component* obj = item.get();
			return dynamic_cast<T*>(obj) != nullptr;
		});
		if (it == components.end()) return nullptr;
		return it->get();
	}

	static vector<unique_ptr<GameObject>> objs;	
	static vector<GameObject *> pendings;


	friend Component;

	void innerUpdate();

	
	
public:
	GameObject(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, const Dimension& dim = { 1, 1 });

	virtual ~GameObject() {
		delete[] shape; 
		shape = nullptr; 
	}

	auto isEnabled() const { return enabled; }
	auto setEnabled(bool enabled) { this->enabled = enabled; if (enabled == true) start(); }

	auto getPos() const { return pos; }

	void setPos(const Position<float>& pos) { this->pos = pos; }

	auto getDimension() const { return dim; }

	auto setDimension(const Dimension& dim) { this->dim = dim; }
		
	const auto getShape() const { return shape; }

	virtual void draw() { screen.draw(Position<int>{(int)pos.x, (int)pos.y}, shape, dim); }

	virtual void start() {}

	virtual void update() {}

	const Screen& getScreen() { return screen; }
	
	static void Initialize(Screen& screen, InputSystem& input);

	static void Update();

	static void DestoryDisabledObjects();

	static void Draw();

	static void Deinitialize();
};

