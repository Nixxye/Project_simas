#pragma once

#include "Character.h"
#include <SFML/Graphics.hpp>
using namespace entes;



class Enemy: public Character
{
protected:
    bool alive;
public:
    Enemy();
    ~Enemy();
    void move();
};
