#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include "../entities/Character.h"
using namespace entes;
using namespace character;
class Player: public Character
{
private:

public:
    Player();
    ~Player();
    void move();
};
