#pragma once

#include "Character.h"
namespace characters
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
        void collide(Entity* other){};
    };
}