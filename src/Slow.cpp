#include "../entities/Slow.h"

namespace Entes
{
    namespace Obstacles
    {
        Slow:: Slow(sf::Vector2f pos, sf::Vector2f size):
        Obstacle(12, pos, size)
        {
            //Provisório:
            body.setFillColor(sf::Color::Green);
        }
        Slow:: ~Slow()
        {
            
        }   
        void Slow::collide(Entity* other, std::string  direction) 
        {
            //std::cout<<"Slowed"<<std::endl;
            other->set_slowed(true);
        }
    }    
}

