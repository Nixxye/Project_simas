#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class Platform : public Obstacle
        {
            private:
                //Criar atributos próprios:
            public:
                Platform(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
                ~Platform();
                void collide(Entity* other, std::string  direction = ""){};
                void run(){}
            
        };    
    }    
}

