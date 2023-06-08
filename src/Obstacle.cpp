#include "../entities/Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        Obstacle::Obstacle(int index, sf::Vector2f pos):
        Entes::Entity(index, sf::Vector2f(0.f, 0.f)),
        body(sf::Vector2f(OBSTACLE_SIZE, OBSTACLE_SIZE))
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

