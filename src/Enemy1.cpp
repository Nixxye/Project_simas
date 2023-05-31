#include "../entities/Enemy1.h"

namespace Entes
{
    namespace Characters
    {
        Enemy1:: Enemy1(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Enemy(1, pos, velocity, size),
        motion_counter(TIME)
        {
            damage = 5;
        }
        Enemy1:: ~Enemy1()
        {
            
        }  
        void Enemy1::move()
        {
            if (speed > 0)
            {
                if (grounded)
                {
                    vel.y -= 5.f;
                }
                if (motion_counter > 0)
                {
                    vel.x += SPEED;
                    motion_counter--;
                    if (motion_counter == 0)
                    {
                        motion_counter = -TIME;
                        vel.x = 0;
                    } 
                }
                else if (motion_counter < 0)
                {
                    vel.x -= SPEED;
                    motion_counter++;
                    if (motion_counter == 0)
                    {
                        motion_counter = TIME;
                        vel.x = 0;
                    }
                }  
                if (!grounded)
                    vel.y += G;             
                position += sf::Vector2f(speed*vel.x / 2, speed*vel.y / 2);
                body.setPosition(position);
            }
        }
        void Enemy1::collide(Entity* other)
        {
            int index = other->get_id();
            //ifs e dano
            sf::Vector2f pos = other->get_position();
            sf::Vector2f s = other->get_size();
            
            if (pos.y + s.y / 2 <= position.y || pos.y - s.y / 2 >= position.y)
            {
                if (pos.x + s.x / 2 >= position.x)
                {
                    motion_counter = - TIME;
                }
                else
                    motion_counter = TIME;                
            }

        }  
    }    
}

