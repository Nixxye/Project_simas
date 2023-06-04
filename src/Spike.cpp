#include "../entities/Spike.h"

namespace Entes
{
    namespace Obstacles
    {
        Spike:: Spike(sf::Vector2f pos, sf::Vector2f size):
        Obstacle(13, pos, size)
        {
            damage = 1;
            texture = pGM->load_textures("../assets/obstacle1.png");
            body.setTexture(texture);
        }
        Spike:: ~Spike()
        {
            
        }
    }    
}

