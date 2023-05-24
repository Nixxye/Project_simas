#include "Character.h"

namespace Entes
{
    namespace Characters
    {
        Character::Character(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Entity(pos, velocity, size)
        {
        }
        Character::~Character()
        {

        }
    }   
}

