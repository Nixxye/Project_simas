#include "../entities/Bomb.h"
#include "../managers/ColisionManager.h"

namespace Entes
{
    namespace Characters
    {
        Bomb::Bomb(bool alv, int lf, sf::Vector2f pos, sf::Vector2f velocity, float dmg, sf::Vector2f size, Lists::EntityList* p, float sr, bool atck, sf::Vector2f axs, float brst, float pw):
        Enemy(2, pos, velocity, size),
        players(p),
        attacking (atck),
        sensor_radius(sr),
        axis(axs),
        power(pw),
        explosion(sensor_radius),
        burst(brst),
        exploding(false)
        {
            damage = dmg;
            life = lf;
            alive = alv;
            
            explosion.setFillColor(sf::Color::Black);
            explosion.setOrigin(sf::Vector2f(sensor_radius, sensor_radius)); 
            if (attacking)
                texture = pGM->load_textures("../assets/bomb1.png"); 
            else 
                texture = pGM->load_textures("../assets/bomb0.png");
            body.setTexture(texture);  
        }
        Bomb:: ~Bomb()
        {
            
        }  
        void Bomb::draw()
        {
            if (alive)
            {
                pGM->draw(&body);
            }
            if (exploding)
            {
                pGM->draw(&explosion);
                exploding = false;
            }
        }
        void Bomb::move()
        {
            if (!players)
            {
                std::cout<<"No players"<<std::endl;
                return;
            }
            if (alive)
            {
                if (speed)
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
                            }
                            aux++;        
                        }  
                    }
                    else 
                    {
                        
                        burst += 0.5;
                        vel = axis*burst;
                        body.setPosition(body.getPosition() + vel * speed / 8.f);  
                    }              
                }
                vel.y += GRAVITY;
                //Flying force:
                vel.y -= GRAVITY;                    
                }

        }
        void Bomb::attack(sf::Vector2f target)
        {
            //Cria o eixo "mira"
            axis = target - body.getPosition();
            axis = axis / sqrt(axis.x * axis.x + axis.y * axis.y);
            attacking = true;
            texture = pGM->load_textures("../assets/bomb1.png"); 
            body.setTexture(texture);
        }
        void Bomb::collide(Entity* other, std::string direction)
        {
            int index = other->get_id();
            
            other->inflict_damage(damage);
            explode();            
        }  
        void Bomb::explode()
        {
            explosion.setPosition(body.getPosition()); 
            exploding = true;

            colision_manager->collide_explosion(&explosion, power);
            alive = false;
        }
        void Bomb::save(std::ofstream& file)
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
            <<sensor_radius<<std::endl;
            if (attacking)
                file<<1<<std::endl;
            else
                file<<0<<std::endl;
            file<<axis.x<<std::endl<<axis.y<<std::endl<<burst<<std::endl<<power<<std::endl<<std::endl;
        }  
    }    
}

