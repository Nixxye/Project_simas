#include "../entities/Entity.h"


int Entes::Entity::count(0);
int Entes::Entity::speed(0);

sf::Vector2f Entes::Entity::player_position(200.f, 200.f);

namespace Entes
{
    Entity::Entity(int index, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
    Ent(),
    damage(0),
    id(index),
    body(size),
    position(pos),
    vel(velocity),
    life(1),
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
        if (alive)
            pGM->draw(&body);
    }


}