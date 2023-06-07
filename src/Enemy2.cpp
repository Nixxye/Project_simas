#include "../entities/Enemy2.h"
#include "../managers/ColisionManager.h"

namespace Entes
{
    namespace Characters
    {
        Enemy2:: Enemy2(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size, Lists::EntityList* p):
        Enemy(2, pos, velocity, size),
        players(p),
        attacking(false),
        axis(1.f, 1.f),
        burst(1.f),
        sensor_radius(400.f),
        explosion(sensor_radius),
        power(40.f)
        {
            body.setSize(sf::Vector2f(10.f, 10.f));
            explosion.setFillColor(sf::Color::Black);
            explosion.setOrigin(sf::Vector2f(sensor_radius, sensor_radius));
        }
        Enemy2:: ~Enemy2()
        {
            
        }  
        void Enemy2::move()
        {
            if (alive)
            {
                if (!attacking)
                {
                    sf::Vector2f d;
                    Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = players->get_first();
                    while(aux != nullptr)
                    {
                        d = body.getPosition() - (*aux)->get_position();
                        if (fabs(d.x) < sensor_radius && fabs(d.y) < sensor_radius)
                        {
                            attack((*aux)->get_position());
                            std::cout<<"Target adquired"<<std::endl;
                        }
                        aux++;        
                    }  
                }
                else 
                {
                    burst += 0.5;
                    vel = axis*burst;
                    body.setPosition(body.getPosition() + vel);  
                }  
                //Teste:
                //explosion.setPosition(body.getPosition()); 
                //pGM->draw(&explosion);              
            }

        }
        void Enemy2::attack(sf::Vector2f target)
        {
            //Cria o eixo "mira"
            axis = target - body.getPosition();
            axis = axis / sqrt(axis.x * axis.x + axis.y * axis.y);
            attacking = true;
        }
        void Enemy2::collide(Entity* other, std::string direction)
        {
            std::cout<<"Colidiu"<<std::endl;
            int index = other->get_id();
            
            other->inflict_damage(damage);
            explode();            
        }  
        void Enemy2::explode()
        {
            explosion.setPosition(body.getPosition()); 
            pGM->draw(&explosion);

            colision_manager->collide_explosion(&explosion, power);
            alive = false;
        }
        void Enemy2::save(std::ofstream& file)
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
            file<<damage<<std::endl
            <<body.getPosition().x<<std::endl<<body.getPosition().y<<std::endl
            <<vel.x<<std::endl<<vel.y<<std::endl
            <<body.getSize().x<<std::endl<<body.getSize().y<<std::endl
            <<sensor_radius<<std::endl;
            if (attacking)
                file<<1<<std::endl;
            else
                file<<0<<std::endl;
            file<<axis.x<<std::endl<<axis.y<<std::endl<<burst<<std::endl<<power<<std::endl<<std::endl;
        }  
    }    
}

