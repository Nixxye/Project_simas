#include "../entities/Platform.h"

namespace Entes
{
    namespace Obstacles
    {
        Platform:: Platform(sf::Vector2f pos, bool check):
        Obstacle(11, pos)
        {
            texture = pGM->load_textures("../assets/plataform.png");
            body.setTexture(texture);
        }
        Platform:: ~Platform()
        {
            
        } 
        void Platform::collide(Entity* other, std::string  direction)
        {

        }   
    }    
}

