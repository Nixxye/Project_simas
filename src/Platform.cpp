#include "../entities/Platform.h"

namespace Entes
{
    namespace Obstacles
    {
        Platform:: Platform(sf::Vector2f pos, sf::Vector2f size, bool check):
        Obstacle(11, pos, size)
        {
            texture = pGM->load_textures("../assets/plataform.png");
            body.setTexture(texture);
        }
        Platform:: ~Platform()
        {
            
        }    
    }    
}

