#include "../entities/Bullet.h"

namespace Entes
{
    Bullet::Bullet(float vx, float vy, float time):
    lifetime(time), 
    body(25)
    {
        vel = sf::Vector2f(vx, vy);
    }
    Bullet::~Bullet()
    {

    }
    void Bullet::run()
    {
        move();
    }
    void Bullet::move()
    {
        if (alive)
        {
            if (!grounded)
                vel.y += G;
            if (speed > 0.f)
                body.setPosition(body.getPosition() + sf::Vector2f(vel.x * speed, vel.y * speed));    
        }
    }
}
