#include "../entities/Obstacle.h"

namespace obstacles
{
    Obstacle::Obstacle(sf::Vector2f pos, sf::Vector2f size):
    Entity(pos, size)
    {

    }
    Obstacle::~Obstacle()
    {
        
    }
    void Obstacle::run(){}    
}
