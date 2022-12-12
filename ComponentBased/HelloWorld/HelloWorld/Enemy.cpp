#include "Enemy.h"


Enemy::Enemy(const char* shape, const Position<int>& pos, Screen& screen, InputSystem& input, const Dimension& dim)
    : GameObject(shape, pos, screen, input, dim)
{}
