#include "../entities/Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        Obstacle::Obstacle(int index, sf::Vector2f pos, sf::Vector2f size):
        Entes::Entity(index, sf::Vector2f(0.f, 0.f)),
        body(size)
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
            if (alive)
                pGM->draw(&body);
        }
    }    
}

