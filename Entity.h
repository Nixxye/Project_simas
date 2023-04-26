#pragma once

#include <SFML/Graphics.hpp>

class Entity
{
protected:
    sf::RectangleShape body;
    static int speed;
    sf::Vector2f position;
public:
    Entity();
    ~Entity();
    void draw(sf::RenderWindow* wd);
    virtual void move() = 0;
};

