#pragma once

#include "Enemy.h"
#include "../lists/EntityList.h"
//TODO: Fazer a função move de enemy ser virtual e enemy 1 receber a função atual;
namespace enemies
{
    class Boss: public Enemy
    {
        public:
            EntityList bullets;
        private:
            void move();
            void attack();
    } 
}
