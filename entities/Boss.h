#pragma once

#include "../entities/Enemy.h"
#include "../lists/EntityList.h"
#include "../entities/Bullet.h"

//TODO: Fazer a função move de enemy ser virtual e enemy 1 receber a função atual;
namespace Entes
{
    namespace Characters
    {
        class Boss: public Enemy
        {
        private:
            Lists::EntityList bullets;
            int attack_delay;
            Bullet b1;
            Bullet b2;
            Bullet b3;
            Bullet b4;
            Bullet b5;
            Bullet b6;
        public:
            Boss();
            ~Boss();
            void execute();
            void move();
            void attack();
            void draw();
            void collide(Entity* other){};
        };
    }
}
