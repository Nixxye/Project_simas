#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class SlimePlatform : public Obstacle
        {
            private:
                 bool slippery;
            public:
                SlimePlatform();
                ~SlimePlatform();
                void collide(Entity* other, std::string  direction = ""){};
                void run(){}
            
        };    
    }    
}

