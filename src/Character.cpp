#include "../entities/Character.h"

namespace Entes
{
    namespace Characters
    {
        Character::Character(int index, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Entity(index, pos, velocity, size)
        {
        }
        Character::~Character()
        {

        }
    }   
}

