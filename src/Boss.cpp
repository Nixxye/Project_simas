#include "../entities/Boss.h"
#include <iostream>
#include "../managers/ColisionManager.h"

#define DELAY 300

namespace Entes
{
    namespace Characters
    {
        Boss::Boss(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Enemy(3, pos, velocity, size),
        bullets(),
        attack_delay(DELAY)
        {
            //Teste:
            //bullets.clear();
            //std::cout<<"N na inicial. "<<bullets.get_size()<<std::endl;
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
            
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = bullets.get_first();

            while(aux != nullptr)
            {
                colision_manager->collide_bullets(*aux);           
                aux++;        
            }
            move();
        }
        void Boss::move()
        {
            bullets.run();
        }

        void Boss::attack()
        {
            std::cout<<"O boss tá lá"<<std::endl;
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = bullets.get_first();
            
            float vx = 0.f, vy = 0.f;

            while(aux != nullptr)
            {
                (*aux)->set_alive(true);

                vx = ((rand() % 50) - 25) / 10.f;
                vy = ((rand() % 50) - 40) / 10.f;
                (*aux)->set_position(body.getPosition());
                (*aux)->set_vel(sf::Vector2f(vx, vy));
                
                aux++;        
            } 
            bullets.set_position(body.getPosition());
        }
        void Boss::collide(Entity* other, std::string direction)
        {
        }
        void Boss::draw()  
        {
            if (alive)
                pGM->draw(&body);
            bullets.draw();
        } 
        void Boss::add_bullet(Entes::Entity* bullet)
        {
            bullets.add(bullet);
        }
    }
}
