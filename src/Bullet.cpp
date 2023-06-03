#include "../entities/Bullet.h"
#include "../managers/ColisionManager.h"

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
        if (alive)
        {
            move();
            lifetime--;
            if (lifetime <= 0)
                alive = false;
        }
        
    }
    void Bullet::set_alive(bool a)
    {
        lifetime = TIME;
        alive = a;
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
    void Bullet::call_colision()
    {
        colision_manager->collide_bullets(this);
    }
    void Bullet::collide(Entity* other, std::string direction)
    {
        int index = other->get_id();
        switch (index)
        {
            //Player:
        case 0:
            colision_manager->elastic_colision(this, other);
            break;
            //Other Bullet:
        case 11:
            if (direction == "Right" || direction == "Left")
            {
                vel = sf::Vector2f(- CR*vel.x, vel.y);
            }
            else 
            {
                vel = sf::Vector2f(vel.x, - CR*vel.y);
            }
        default:
            break;
        }
        move();
    }
}
