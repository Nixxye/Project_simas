#include "../entities/Spike.h"

namespace Entes
{
    namespace Obstacles
    {
        Spike:: Spike(sf::Vector2f pos, sf::Vector2f size):
        Obstacle(13, pos, size)
        {
            damage = 1;
            body.setFillColor(sf::Color::Red);
        }
        Spike:: ~Spike()
        {
            
        }
    }    
}

