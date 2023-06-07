#include "../entities/Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        Obstacle::Obstacle(int index, sf::Vector2f pos):
        Entes::Entity(index, sf::Vector2f(0.f, 0.f)),
        body(sf::Vector2f(50.f, 50.f))
        {
            body.setOrigin(body.getSize()/2.f);
            body.setPosition(pos);
            
        }
        Obstacle::~Obstacle()
        {
            
        }
        void Obstacle::execute(){}    
        void Obstacle::draw()
        {
            if(get_alive())
                pGM->draw(&body);
        }
    }    
}

