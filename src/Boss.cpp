#include "../entities/Boss.h"
#include <iostream>
#include "../managers/ColisionManager.h"

#define DELAY 300

namespace Entes
{
    namespace Characters
    {
        Boss::Boss(bool alv, int lf, sf::Vector2f pos, sf::Vector2f velocity, float dmg, sf::Vector2f size, int attck_delay):
        Enemy(3, pos, velocity, size),
        bullets(), 
        attack_delay(attck_delay)
        {
            texture = pGM->load_textures("../assets/boss.png");
            body.setTexture(texture);
            alive = alv;
            life = lf;
            damage = dmg;
        }
        Boss::~Boss()
        {
            bullets.clear();
        }
        void Boss::execute()
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
            vel.y += GRAVITY;
            if (grounded)
                vel.y -= GRAVITY;
            vel.y -= (rand() % (int) (10*GRAVITY)) / 10.f + GRAVITY * 2 / 3;
            body.setPosition(body.getPosition() + vel*(float) speed);
            bullets.execute();
        }

        void Boss::attack()
        {
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = bullets.get_first();
            float vx = 0.f, vy = 0.f;

            while(aux != nullptr)
            {
                static_cast<Entes::Bullet*>(*aux)->set_alive(true);
                (static_cast<Entes::Bullet*>(*aux))->set_friendly(false);
                (static_cast<Entes::Bullet*>(*aux))->set_fill_color(sf::Color::White);              
                vx = ((rand() % 50) - 25) / 30.f;
                vy = ((rand() % 50) - 40) / 30.f;
                (*aux)->set_position(body.getPosition());
                (*aux)->set_vel(sf::Vector2f(vx, vy));
                
                aux++;        
            } 
            bullets.set_position(body.getPosition());
        }
        void Boss::collide(Entity* other, std::string direction)
        {
            int index = other->get_id();
            switch (index)
            {
            case 1:
                other->inflict_damage(damage);
                break;
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
        void Boss::save(std::ofstream& file)
        {
            if (!file.is_open())
            {
                std::cout<<"Error: Cannot open enemy file!"<<std::endl;
                return;
            }
            file<<id<<std::endl;
            if (alive)
                file<<1<<std::endl;
            else
                file<<0<<std::endl;
            file<<life<<std::endl<<damage<<std::endl
            <<body.getPosition().x<<std::endl<<body.getPosition().y<<std::endl
            <<vel.x<<std::endl<<vel.y<<std::endl
            <<body.getSize().x<<std::endl<<body.getSize().y<<std::endl
            <<attack_delay<<std::endl<<bullets.get_size()<<std::endl<<std::endl;

            bullets.save(file);
        }
    }
}
