#pragma once

#include "Character.h"
#include <SFML/Graphics.hpp>
using namespace entes;
using namespace character;


class Enemy: public Character
{
protected:

public:
    Enemy();
    ~Enemy();
    void move();
};
