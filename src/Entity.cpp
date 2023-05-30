#include "../entities/Entity.h"

int Entes::Entity::speed(0);
int Entes::Entity::count(0);
sf::Vector2f Entes::Entity::player_position(200.f, 200.f);

namespace Entes
{
    Entity::Entity(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
    GameObject(),
    body(size),
    position(pos),
    vel(velocity),
    lives(1),
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

    void Entity::draw()
    {
        graphics_manager->draw(&body);
    }
}