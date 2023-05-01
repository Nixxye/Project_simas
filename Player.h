#pragma once

#define SPEED 0.1
#define VEL_MAX 1.5
#include <SFML/Graphics.hpp>
#include <math.h>

#include "Entity.h"
#include "Personagem.h"


class Player: public Personagem
{
private:

public:
    Player();
    ~Player();
    void move();
};
