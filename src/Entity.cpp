#include "../entities/Entity.h"

#include "../managers/ColisionManager.h"

int Entes::Entity::count(0);
float Entes::Entity::speed(0);


sf::Vector2f Entes::Entity::player_position(200.f, 200.f);

namespace Entes
{
    Entity::Entity(int index, sf::Vector2f velocity):
    Ent(),
    id(index),
    colision_manager(nullptr),
    vel(velocity),
    grounded(false),
    //Arrumar a massa dps:
    mass(1),
    slowed(1)
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
    /*
    void Entity::draw()
    {
        //if (this->get_alive())
            //pGM->draw(&body);
    }
*/

}