#pragma once

#include <SFML/Graphics.hpp>
#include "../managers/GraphicsManager.h"

#define G 0.3
#define SPEED 0.2
#define VEL_MAX 4.0

class GameObject
{
protected:

    const int id;
    static int count;
    sf::RectangleShape body;
    static int speed;
    sf::Vector2f position;
    static Managers::GraphicsManager* graphics_manager;
    sf :: Texture* texture;
public:
    GameObject();
    virtual ~GameObject();

    virtual void draw() = 0;

    void set_position(sf::Vector2f pos){body.setPosition(pos);}



    int get_speed(){return speed;}

    sf::Vector2f get_position(){return body.getPosition();}
    sf::Vector2f get_size(){return body.getSize();} 
};

