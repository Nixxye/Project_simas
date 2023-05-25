#pragma once 
#include "Enemy.h"

namespace Entes
{
    namespace Characters
    {
        class Enemy2: public Enemy
        {
        private:
        public:
            Enemy2();
            ~Enemy2();
            void collide(Entity* other){};
        
        };    
    }
}

