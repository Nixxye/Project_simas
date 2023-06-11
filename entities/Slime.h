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
                Slime(sf::Vector2f pos, int sl = 4);
                ~Slime();
                void collide(Entity* other, std::string  direction = "");
                void execute();
                void move();
        };    
    }    
}

