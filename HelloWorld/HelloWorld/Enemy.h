#pragma once
#include <conio.h>
#include "GameObject.h"
class Enemy :
    public GameObject
{

    auto walkRandomly()
    {
        static Position<float> idx2inc[] = { {-1.f, -1.f}, { 0.f, -1.f}, {1.f, -1.f}, {-1.f,0.f}, {0.f, 0.f},
            {1.f, 0.f}, { -1.f, 1.f}, {0.f, 1.f}, {1.f, 1.f} };

        setPos( getPos() + idx2inc[ rand() % 9 ] ) ;
    }

    void processInput()
    {
        auto pos = getPos();
        if (input.getKey(VK_LEFT)) { // left arrow
            pos.x--;
        }
        else if (input.getKey(VK_RIGHT)) { // right arrow
            pos.x++;
        }
        else if (input.getKey(VK_UP)) { // up arrow
            pos.y--;
        }
        else if (input.getKey(VK_DOWN)) { // down arrow
            pos.y++;
        }
        setPos(pos);

        if (input.getMouseButtonDown(0)) {
            auto mousePos = input.getMousePosition();
            Borland::printf("mouse position [%03d, %03d]\n", mousePos.x, mousePos.y);
        }
    }

public:
    Enemy(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, const Dimension& dim = { 1,1 });

    ~Enemy() {
        Borland::printf("Enemy %p destructed", this);
    }

    void update() override {
        //walkRandomly();
        processInput();
    }

    void draw() override
    {
        GameObject::draw();
        //screen.draw(getPos() + Position{ 0, -1 }, 'E');
    }
};

