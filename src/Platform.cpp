#include "../entities/Platform.h"

namespace Entes
{
    namespace Obstacles
    {
        Platform:: Platform(sf::Vector2f pos, sf::Vector2f size):
        Obstacle(11, pos, size)
        {
            texture = pGM->load_textures("../assets/obstacle.png");
            body.setTexture(texture);
        }
        Platform:: ~Platform()
        {
            
        }    
    }    
}

