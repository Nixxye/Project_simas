#pragma once

#include <SFML/Graphics.hpp>

#define SPEED 0.2
#define VEL_MAX 4

class Entity
{
protected:
    sf::RectangleShape body;
    static int speed;
    sf::Vector2f position;
    static sf::Vector2f player_position;
    int lives;
    sf::Vector2f vel;
public:
    Entity();
    ~Entity();
    void draw(sf::RenderWindow* wd);
    virtual void move() = 0;
};

