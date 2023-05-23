#include "../entities/Boss.h"
#include <iostream>

#define DELAY 1000

namespace entes
{
    namespace Characters
    {
        Boss::Boss():
        Enemy(),
        bullets(),
        attack_delay(DELAY),
        b1(),
        b2(),
        b3(),
        b4(),
        b5(),
        b6()
        {
            body.setPosition(300.f, 100.f);

            bullets.add(static_cast<Entity*>(&b1));
            bullets.add(static_cast<Entity*>(&b2));
            bullets.add(static_cast<Entity*>(&b3));
            bullets.add(static_cast<Entity*>(&b4));
            bullets.add(static_cast<Entity*>(&b5));
            bullets.add(static_cast<Entity*>(&b6));
        }
        Boss::~Boss()
        {

        }
        void Boss::run()
        {
            attack_delay--;
            if (attack_delay < 0)
            {
                attack();
                attack_delay = DELAY;
            }
            
        }
        void Boss::move()
        {

        }

        void Boss::attack()
        {
            b1.set_vel(sf::Vector2f(1.f, 0.f));
            b2.set_vel(sf::Vector2f(-1.f, 0.f));
            b3.set_vel(sf::Vector2f(1.f, -1.f));
            b4.set_vel(sf::Vector2f(-1.f, -1.f));
            b5.set_vel(sf::Vector2f(1.f, -2.f));
            b6.set_vel(sf::Vector2f(-1.f, -2.f));

            bullets.set_position(sf::Vector2f(300.f, 100.f));
        }
        void Boss::draw()  
        {
            Entity::draw();
            bullets.draw();
        }  
    }
}
