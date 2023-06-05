#include "../entities/Character.h"

namespace Entes
{
    namespace Characters
    {
        Character::Character(int index, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Entity(index, velocity),
        body(size),
        alive(true),
        life(1)
        {
            body.setOrigin(body.getSize()/2.f);
            body.setPosition(pos);
        }
        Character::~Character()
        {

        }
        void Character::draw()
        {
            if (alive)
                pGM->draw(&body);
        }
    }   
}

