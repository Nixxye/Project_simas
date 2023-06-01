#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class Obstacle2 : public Obstacle
        {
            private:
            public:
                Obstacle2();
                ~Obstacle2();
                void collide(Entity* other, std::string  direction = ""){};
                void run(){}
            
        };    
    }    
}

