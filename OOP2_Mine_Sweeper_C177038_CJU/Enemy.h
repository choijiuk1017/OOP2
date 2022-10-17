#pragma once
#include "GameObject.h"

class Enemy : public GameObject
{
    int posX;
    int posY;
public:
    Enemy(int x = rand()% 10, int y = rand() % 10) : GameObject('*', x, y)
    {
        posX = x;
        posY = y;
    }

    int getX()
    {
        return posX;
    }

    int getY()
    {
        return posY;
    }

    
};

