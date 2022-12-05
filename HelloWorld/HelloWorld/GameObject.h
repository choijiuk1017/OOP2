#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "Utils.h"
#include "Screen.h"
#include "InputSystem.h"

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

	static vector<GameObject*> objs;
	static vector<GameObject*> pendingObjs;
	
	
public:
	GameObject(const char* shape, const Position<int>& pos, Screen & screen, InputSystem& input, Dimension dim = { 1, 1 } )
		: pos(Position<float>{(float)pos.x, (float)pos.y}), shape(nullptr), dim(dim), screen(screen), input(input), enabled(true)
	{
		cout << "game object constructor[" << this << "]:"<< pos << endl;

		this->shape = new char[dim.size() + 1];
		size_t len = strlen(shape) ;
		if (len > dim.size()) len = dim.size();
		strncpy(this->shape, shape, len);
		this->shape[len] = 0;
		//pendingObjs.push_back(this); 코드를 읽는 사람이 더욱 편한게 좋음
	}

	GameObject(const GameObject& other) : GameObject(other.shape, other.pos, other.screen, other.input, other.dim)
	{
		cout << "game object copy constructor[" << this << "]:" << pos << endl;
	}

	virtual ~GameObject() {
		cout << "game object destructor: " << this << endl;
		delete[] shape; 
		shape = nullptr; 
	}

	auto isEnabled() const { return enabled; }
	auto setEnabled(bool enabled) { this->enabled = enabled; }

	auto getPos() const { return pos; }

	void setPos(const Position<float>& pos)
	{
		this->pos = pos;
	}

	auto getDimension() const { return dim; }

	auto setDimension(const Dimension& dim) { this->dim = dim; }
		
	const auto getShape() const { return shape; }

	virtual void draw()
	{
		screen.draw(Position<int>{(int)pos.x, (int)pos.y}, shape, dim);
	}

	virtual void update() {}	
	
	static void Initialize(Screen& screen, InputSystem& input);

	static void Update();

	static void DestoryDisabledObjects();

	static void Draw();

	static void Deinitialize();
};

