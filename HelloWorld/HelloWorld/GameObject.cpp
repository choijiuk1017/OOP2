#include <vector>
#include <algorithm>
#include <memory>
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Utils.h"

using namespace std;

//정의는 헤더 파일에 하면 안됨
//무조건 소스 파일에 정의
vector<GameObject *> GameObject::objs;
vector<GameObject*> GameObject::pendingObjs;


void GameObject::Initialize(Screen& screen, InputSystem& input)
{
	pendingObjs.push_back(new Enemy("\xB0\xB0", { 10, 5 }, screen, input, { 2, 1 }));
	pendingObjs.push_back(new Enemy("\xB0\xB0", { 5, 7 }, screen, input, { 2, 1 }));
	pendingObjs.push_back(new Enemy("\xB0\xB0", { 60, 18 }, screen, input, { 2, 1 }));
	pendingObjs.push_back(new Player("\xB2\xB2\xB2\xB2 \xB2\xB2 \xB2", { 40, 10 }, screen, input, { 3, 3 }));
}

void GameObject::Update()
{	
	while (!pendingObjs.empty()) {
		objs.push_back( pendingObjs.back() );
		pendingObjs.pop_back();
	}
	for (auto obj : objs)
		obj->update();
}

void GameObject::DestoryDisabledObjects()
{
	objs.erase(remove_if(objs.begin(), objs.end(),
		[](auto& obj) {
			if (!obj->isEnabled())
			{
				return
			}
		}
		),
		objs.end()
			);

	for (auto it = objs.begin(); it != objs.end();) {
		auto obj = *it;
		if (obj->isEnabled()) {
			it++;
			continue;
		}
		it = objs.erase(it);
		delete obj;
	}
}

void GameObject::Draw()
{
	Borland::GotoXY(0, 30);
	cout << "objects = " << objs.size() << " ";

	for (auto obj : objs)
		obj->draw();
}

void GameObject::Deinitialize()
{	
}