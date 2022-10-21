#pragma once
#include <conio.h>
#include "GameObject.h"
class Enemy :
    public GameObject
{

    auto walkRandomly()
    {
        static Position idx2inc[] = { {-1, -1}, { 0, -1}, {1, -1}, {-1,0}, {0, 0},
            {1, 0}, { -1, 1}, {0, 1}, {1, 1} };

        setPos( getPos() + idx2inc[ rand() % 9 ] ) ;
    }

    void processInput()
    {
        auto pos = getPos();
        if (InputSystem::GetKey(224, 'K')) { // left arrow
            pos.x--;
        }
        else if (InputSystem::GetKey(224, 'M')) { // right arrow
            pos.x++;
        }
        else if (InputSystem::GetKey(224, 'H')) { // up arrow
            pos.y--;
        }
        else if (InputSystem::GetKey(224, 'P')) { // down arrow
            pos.y++;
        }
        setPos(pos);
    }

public:
    Enemy(int x, int y, Screen& screen) 
        : GameObject('*', x, y, screen) 
    {}

    void update() override {
        //walkRandomly();
        processInput();
    }
};

