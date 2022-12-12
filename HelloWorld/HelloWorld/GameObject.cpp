#include <vector>
#include <algorithm>
#include <iomanip>
#include <memory>
#include <utility>
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Utils.h"
#include "Component.h"

vector<unique_ptr<GameObject>> GameObject::objs;
vector<GameObject*> GameObject::pendings;

using namespace std;

GameObject::GameObject(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, const Dimension& dim)
	: pos(pos), shape(nullptr), dim(dim), screen(screen), input(input), enabled(true)
{
	this->shape = new char[dim.size() + 1];
	size_t len = strlen(shape);
	if (len > dim.size()) len = dim.size();
	strncpy(this->shape, shape, len);
	this->shape[len] = 0;
}



void GameObject::innerUpdate()
{
	update();
	for (auto& component : components)
		component->update();
}


void GameObject::Initialize(Screen& screen, InputSystem& input)
{
	objs.push_back(move(unique_ptr<GameObject>(new Enemy((const char*)"\xB0\xB0", { 10, 5 }, screen, input, { 2, 1 }))));
	objs.push_back(move(unique_ptr<GameObject>(new Enemy((const char*)"\xB0\xB0", { 5, 7 }, screen, input,  { 2, 1 }))));
	objs.push_back(move(unique_ptr<GameObject>(new Enemy((const char*)"\xB0\xB0", { 60, 18 }, screen, input,{ 2, 1 }))));
	objs.push_back(move(unique_ptr<GameObject>(new Player((const char*)"\xB2\xB2\xB2\xB2 \xB2\xB2 \xB2", { 40, 10 }, screen, input, { 3, 3 }))));
}


void GameObject::Update()
{	
	for (auto& obj : objs)
		obj->innerUpdate();
}

void GameObject::DestoryDisabledObjects()
{
	for (auto it = objs.begin(); it != objs.end();) {
		auto& obj = *it;
		if (obj->isEnabled()) {
			it++;
			continue;
		}
		it = objs.erase(it);
		// CAUTION: do i need to call delete on obj?
	}
	for (auto it = pendings.begin(); it != pendings.end();) {
		auto& obj = *it;
		if (!obj->isEnabled()) {
			it++;
			continue;
		}
		objs.push_back(unique_ptr<GameObject>(obj));
		it = pendings.erase(it);
	}
}

void GameObject::Draw()
{
	Borland::GotoXY(0, 40);
	printf("objects = %5lld", objs.size());

	for (auto& obj : objs)
		obj->draw();
}

void GameObject::Deinitialize()
{	
}