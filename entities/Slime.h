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
                Slime(sf::Vector2f pos, int sl = 60);
                ~Slime();
                void collide(Entity* other, std::string  direction = "");
                void execute(){}
                void set_slow_level(int s) { slow_level = s; }           
        };    
    }    
}

