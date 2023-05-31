#pragma once

#include "../entities/Character.h"
namespace Entes
{
    namespace Characters
    {
        class Bullet: public Character
        {
            private:
                float lifetime;
            public:
                Bullet(float vx = 0.f, float vy = 0.f, float time = 100.f);
                ~Bullet();
                void run();
                void move();
                void collide(Entity* other, std::string direction = ""){};
        };  
    }
}
