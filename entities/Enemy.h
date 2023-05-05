#pragma once

#include "../entities/Entity.h"
#include <SFML/Graphics.hpp>

class Enemy: public Entity
{
private:
    bool alive;
public:
    Enemy();
    ~Enemy();
    void move();
};
