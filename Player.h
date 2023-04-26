#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include "Entity.h"

class Player: public Entity
{
private:

public:
    Player();
    ~Player();
    void move();
};
