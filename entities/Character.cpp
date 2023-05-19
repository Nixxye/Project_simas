#include "Character.h"

namespace characters
{
    Character::Character(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
    Entity(pos, velocity, size)
    {
    }
    Character::~Character()
    {

    }
}
