#include "../entities/Slime.h"

#include <math.h>

namespace Entes
{
    namespace Obstacles
    {
        Slime:: Slime(sf::Vector2f pos, int sl):
        Obstacle(12, pos),
        slow_level(sl)
        {
            //Provisório:
            //body.setFillColor(sf::Color::Green);
            //Slow level padrão é 60
            texture = pGM->load_textures("../assets/obstacle.png");
            body.setTexture(texture);
        }
        Slime:: ~Slime()
        {
            
        }   
        void Slime::collide(Entity* other, std::string  direction) 
        {
            //std::cout<<"Slowed"<<std::endl;
            other->set_slowed(slow_level);
            if (direction == "Above")
            {
                //other->set_grounded(true);
                //other->move('U');
            }
                
                //Teste:
        }
    }    
}

