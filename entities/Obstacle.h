#pragma once
#include "../entities/Entity.h"
class Obstacle: public Entity
{
private:
public:
    Obstacle(sf::Vector2f pos = sf::Vector2f(100.f, 700.f), sf::Vector2f size = sf::Vector2f(1000.f, 100.f));
    ~Obstacle();
    void move();
};