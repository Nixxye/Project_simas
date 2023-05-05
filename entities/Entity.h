#pragma once

#include <SFML/Graphics.hpp>
#define G 0.09
#define SPEED 0.2
#define VEL_MAX 4.0

class Entity
{
protected:
    const int id;
    static int count;
    sf::RectangleShape body;
    static int speed;
    sf::Vector2f position;
    static sf::Vector2f player_position;
    int lives;
    sf::Vector2f vel;
    bool grounded;
public:
    Entity();
    ~Entity();

    void draw(sf::RenderWindow* wd);
    virtual void move() = 0;

    void set_position(sf::Vector2f pos){position = pos;}
    void set_vel(sf::Vector2f v){vel = v;}
    void set_grounded(bool g){grounded = g;}

    int get_speed(){return speed;}
    sf::Vector2f get_vel(){return vel;}
    sf::Vector2f get_position(){return position;}
    sf::Vector2f get_size(){return body.getSize();}    
    //if grounded -> without g effects;
};

