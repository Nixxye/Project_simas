#pragma once

#include <SFML/Graphics.hpp>
#define G 0.2
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
public:
    GameObject();
    virtual ~GameObject();

    virtual void draw(sf::RenderWindow* wd) = 0;

    void set_position(sf::Vector2f pos){body.setPosition(pos);}



    int get_speed(){return speed;}

    sf::Vector2f get_position(){return body.getPosition();}
    sf::Vector2f get_size(){return body.getSize();} 
    
    //função de teste
    void troca_cor(){
        if (body.getFillColor() == sf::Color::Red)
            body.setFillColor(sf::Color::Green);
        else
            body.setFillColor(sf::Color::Red);
    }   
    //if grounded -> without g effects;
};

