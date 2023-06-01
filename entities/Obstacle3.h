#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class Obstacle3 : public Obstacle
        {
            private:
            public:
                Obstacle3();
                ~Obstacle3();
                void collide(Entity* other, std::string  direction = ""){};
                void run(){}
        };    
    }    
}

