#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include "../entities/Character.h"
using namespace entes;
class Player: public Character
{
private:

public:
    Player();
    ~Player();
    void move();
};
