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
        attack_delay(0)
        {
            life = 30;
            //Teste:
            //bullets.clear();
            //std::cout<<"N na inicial. "<<bullets.get_size()<<std::endl;
        }
        Boss::~Boss()
        {
            bullets.clear();
        }
        void Boss::run()
        {
            if (alive && life < 0)
                alive = false;
            attack_delay--;
            if (attack_delay < 0)
            {
                attack();
                attack_delay = DELAY;
            }
            
            //Verifica as colisões das bolinhas:
            //collide_bullets();
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = bullets.get_first();
            while (aux != nullptr)
            {
                (static_cast<Entes::Bullet*>(*aux))->call_colision();
                aux++;
            }
            move();
        }
        void Boss::move()
        {
            if (!grounded)
                vel.y += G;
            //Voar voar, subir subir...
            vel.y -= (rand() % (int) (10*G)) / 10.f + G * 2 / 3;
            body.setPosition(body.getPosition() + vel);
            bullets.run();
        }

        void Boss::attack()
        {
            //std::cout<<"O boss tá lá"<<std::endl;
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = bullets.get_first();
            
            float vx = 0.f, vy = 0.f;

            while(aux != nullptr)
            {
                (*aux)->set_alive(true);
                //std::cout<<"Aqui"<<std::endl;
                (static_cast<Entes::Bullet*>(*aux))->set_friendly(false);
                //Fazer uma função de trocar textura:
                (static_cast<Entes::Bullet*>(*aux))->set_fill_color(sf::Color::White);              
                //std::cout<<"Aquiiii"<<std::endl;
                vx = ((rand() % 50) - 25) / 10.f;
                vy = ((rand() % 50) - 40) / 10.f;
                (*aux)->set_position(body.getPosition());
                (*aux)->set_vel(sf::Vector2f(vx, vy));
                
                aux++;        
            } 
            bullets.set_position(body.getPosition());
            //std::cout<<"Saiu do ataque"<<std::endl;
        }
        void Boss::collide(Entity* other, std::string direction)
        {
            int index = other->get_id();
            Entes::Bullet* bullet = nullptr;
            if (index == 4)
                Entes::Bullet* bullet = static_cast<Entes::Bullet*>(other);
            switch (index)
            {
                /*
            case 4:
                if(bullet->get_friendly())
                {
                    life -= bullet->get_damage();
                }
                break;
 */
            case 11:
                if (direction == "Right" || direction == "Left")
                {
                    vel = sf::Vector2f(- CR*vel.x, vel.y);
                }
                else 
                {
                    vel = sf::Vector2f(vel.x, - CR*vel.y);
                }
                break;
            
            default:
                break;
            }
        }
        void Boss::draw()  
        {
            if (alive)
            {
                pGM->draw(&body);
            }
            bullets.draw();
        } 
        void Boss::add_bullet(Entes::Entity* bullet)
        {
            bullets.add(bullet);
        }
        void Boss::collide_bullets()
        {
            for (Lists::List<Entes::Entity>::Iterator<Entes::Entity> i = bullets.get_first(); i != nullptr; i++)
                for (Lists::List<Entes::Entity>::Iterator<Entes::Entity> j = bullets.get_first(); j != nullptr; j++)
                {
                    colision_manager->elastic_colision(*i, *j);
                }
        }
    }
}
