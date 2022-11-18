#pragma once
#include "GameObject.h"
#include "Utils.h"

class Bullet :
    public GameObject
{
    Position<float> direction;

public:
    Bullet(const Position<float>& dir, const Position<int>& pos, Screen& screen, InputSystem& input)
        : GameObject("*", pos, screen, input, {1,1}), direction(dir)
    {}

    void update() override {
        setPos(getPos() + direction * 0.1f);
        if (screen.checkValidPos( getPos() ) == false)
            setEnabled(false);        
    }
};

