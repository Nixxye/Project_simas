#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class Obstacle1 : public Obstacle
        {
            private:
            public:
                Obstacle1();
                ~Obstacle1();
                void collide(Entity* other, std::string  direction = ""){};
                void run(){}
            
        };    
    }    
}

