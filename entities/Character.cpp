#include "Character.h"

namespace characters
{
    Character::Character(sf::Vector2f pos, sf::Vector2f size, sf::Vector2f velocity):
    Entity(pos, size)
    {
        vel = velocity;
    }
    Character::~Character()
    {

    }
}
