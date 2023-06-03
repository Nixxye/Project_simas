#include "../entities/Bullet.h"

namespace Entes
{
    Bullet::Bullet(sf::Vector2f pos, sf::Vector2f velocity, float time):
    Entity(4, velocity),
    lifetime(time), 
    body(10)
    {
        body.setPosition(pos);
        //vel = velocity;
    }
    Bullet::~Bullet()
    {

    }
    void Bullet::run()
    {
        move();
    }
    void Bullet::draw()
    {
        pGM->draw(&body);
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
