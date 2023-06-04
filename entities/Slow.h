#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class Slow : public Obstacle
        {
            private:
            public:
                Slow(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
                ~Slow();
                void collide(Entity* other, std::string  direction = "");
                void run(){}
            
        };    
    }    
}

