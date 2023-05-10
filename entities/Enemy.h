#pragma once

#include "Character.h"
#include <SFML/Graphics.hpp>
using namespace entes;
using namespace character;


class Enemy: public Character
{
protected:
    bool alive;
public:
    Enemy(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
    ~Enemy();
    void move();
};
