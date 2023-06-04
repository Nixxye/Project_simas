#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class PoisonousPlatform : public Obstacle
        {
            private:
                int poison_level;
            public:
                PoisonousPlatform();
                ~PoisonousPlatform();
                void collide(Entity* other, std::string  direction = ""){};
                void execute(){}
            
        };    
    }    
}

