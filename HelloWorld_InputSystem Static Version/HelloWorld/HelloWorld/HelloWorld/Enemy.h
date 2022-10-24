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
        if (input.getKeyDown(VK_LEFT)) { // left arrow
            pos.x--;
        }
        else if (input.getKeyDown(VK_RIGHT)) { // right arrow
            pos.x++;
        }
        else if (input.getKeyDown(VK_UP)) { // up arrow
            pos.y--;
        }
        else if (input.getKeyDown(VK_DOWN)) { // down arrow
            pos.y++;
        }
        setPos(pos);

        if (input.getMouseButtonDown(0))
        {
            auto mousePos = input.getMousePosition();
            Borland::GotoXY(0, 28);
            printf("mouse position[%d, %d]\n", mousePos.x, mousePos.y);
        }
    }

public:
    Enemy(int x, int y, Screen& screen, InputSystem& input)
        : GameObject('*', x, y, screen, input) 
    {}

    void update() override {
        //walkRandomly();
        processInput();
    }
};

