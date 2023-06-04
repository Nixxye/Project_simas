#include "../entities/Entity.h"

#include "../managers/ColisionManager.h"

int Entes::Entity::count(0);
int Entes::Entity::speed(0);


sf::Vector2f Entes::Entity::player_position(200.f, 200.f);

namespace Entes
{
    Entity::Entity(int index, sf::Vector2f velocity):
    Ent(),
    damage(0),
    id(index),
    colision_manager(nullptr),
    vel(velocity),
    life(1),
    grounded(false),
    alive(true),
    //Arrumar a massa dps:
    mass(1),
    slowed(false)
    {
        //body.setPosition(pos);
        /*
        body.setFillColor(sf::Color::White);
        
        body.setOrigin(body.getSize()/2.f);
        */
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