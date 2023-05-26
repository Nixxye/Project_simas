#include "../entities/Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        Obstacle::Obstacle(sf::Vector2f pos, sf::Vector2f size):
        Entes::Entity(pos, sf::Vector2f(0.f, 0.f), size)
        {

        }
        Obstacle::~Obstacle()
        {
            
        }
        void Obstacle::run(){}    
    }    
}

