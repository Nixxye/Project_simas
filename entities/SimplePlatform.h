#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class SimplePlatform: public Obstacle
        {
            private:
                bool flying;
            public:
                SimplePlatform();
                ~SimplePlatform();
                void collide(Entity* other, std::string  direction = ""){};
                void execute(){}
        };    
    }    
}

