#include "../entities/Obstacle.h"

namespace obstacles
{
    Obstacle::Obstacle(sf::Vector2f pos, sf::Vector2f size):
    Entity(pos, sf::Vector2f(0.f, 0.f), size)
    {

    }
    Obstacle::~Obstacle()
    {
        
    }
    void Obstacle::run(){}    
}
