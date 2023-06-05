#include "../entities/Slime.h"

#include <math.h>

namespace Entes
{
    namespace Obstacles
    {
        Slime:: Slime(sf::Vector2f pos, sf::Vector2f size):
        Obstacle(12, pos, size),
        slow_level(60)
        {
            //Provisório:
                body.setFillColor(sf::Color::Green);
            //texture = pGM->load_textures("../assets/obstacle.png");
            //body.setTexture(texture);
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

