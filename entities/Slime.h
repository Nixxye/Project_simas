#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class Slime : public Obstacle
        {
            private:
                int slow_level;
            public:
                Slime(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
                ~Slime();
                void collide(Entity* other, std::string  direction = "");
                void execute(){}
                void set_slow_level(int s) { slow_level = s; }           
        };    
    }    
}

