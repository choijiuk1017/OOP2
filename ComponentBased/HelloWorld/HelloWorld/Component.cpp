#include "GameObject.h"
#include "Component.h"

Component::Component(GameObject* gameObject) : gameObject(gameObject)
{
	start();
}

Component::~Component() { onDestory(); }