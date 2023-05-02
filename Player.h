#pragma once

#define SPEED 0.1
#define VEL_MAX 1.5
#include <SFML/Graphics.hpp>
#include <math.h>

#include "Entity.h"

class Player: public Entity
{
private:
    sf::Vector2f vel;
public:
    Player();
    ~Player();
    void move();
};
