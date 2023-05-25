#pragma once 
#include "Enemy.h"

namespace characters
{
    class Enemy3 : public Enemy
    {
        private:
        public:
            Enemy3();
            ~Enemy3();
            void collide(Entity* other){};
        
    };    
}
