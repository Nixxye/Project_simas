#include "Entity.h"

int entes::Entity::speed(0);
int entes::Entity::count(0);
sf::Vector2f entes::Entity::player_position(200.f, 200.f);

namespace entes
{
    Entity::Entity(sf::Vector2f pos, sf::Vector2f size):
    GameObject(),
    id(count++),
    body(size),
    position(pos),
    lives(1),
    vel(0.f, 0.f),
    grounded(false),
    alive(true)
    {
        
        body.setFillColor(sf::Color::White);
        body.setPosition(pos);
        body.setOrigin(body.getSize()/2.f);
    }

    Entity::~Entity()
    {

    }

    void Entity::draw(sf::RenderWindow *wd)
    {
        wd->draw(body);
    }
}