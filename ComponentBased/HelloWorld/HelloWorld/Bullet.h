#pragma once
#include "GameObject.h"
#include "MoveScript.h"
class Bullet :
    public GameObject
{
public:
    Bullet(const Position<float>& dir, const Position<int>& pos, Screen& screen, InputSystem& input)
        : GameObject("*", pos, screen, input, { 1,1 })
    {
        auto moveScript = new MoveScript(this);
        addComponent<Component>(moveScript);
        moveScript->moveToDirection(dir);
    }
};

