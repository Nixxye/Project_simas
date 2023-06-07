#include "../entities/Enemy1.h"

namespace Entes
{
    namespace Characters
    {
        Enemy1:: Enemy1(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Enemy(1, pos, velocity, size),
        motion_counter(TIME)
        {
            damage = 2;
            life = 10;
            texture = pGM->load_textures("../assets/enemy3.png");
            body.setTexture(texture);
        }
        Enemy1:: ~Enemy1()
        {
            
        }  
        void Enemy1::move()
        {
            if (speed > 0)
            {
                /*
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
                */
                if (grounded)
                {
                    vel.y -= 5.f;
                }
                else
                    vel.y += G;      
                if (motion_counter > 0)
                    vel.x += SPEED / 4;
                else 
                    vel.x -= SPEED / 4;      
                body.setPosition(body.getPosition() + sf::Vector2f(speed*vel.x / 10, speed*vel.y / 10));
            }
        }
        void Enemy1::collide(Entity* other, std::string direction)
        {
            int index = other->get_id();
            //ifs e dano
            sf::Vector2f pos = other->get_position();
            sf::Vector2f s = other->get_size();

            switch (index)
            {
                //Attack -> arrumar o lance do id dps:
            case 0:
                if(!static_cast<Entes::Characters::Player*>(other)->get_damage())
                {
                    if (direction == "Right")
                    {
                        other->inflict_damage(damage);
                        vel.x = -100*SPEED;
                        //std::cout<<direction<<std::endl;
                    }
                    else if (direction == "Left")
                    {
                        other->inflict_damage(damage);
                        vel.x = 100*SPEED;
                    }
                    else if (direction == "Above")
                    {
                        vel.y = 100*SPEED;
                    }
                    else if (direction == "Below")
                    {
                        other->inflict_damage(damage);
                        vel.y = -40*SPEED;
                    }                    
                }
                else 
                {
                    if (direction == "Right")
                    {
                        vel.x = -100*SPEED;
                        //std::cout<<direction<<std::endl;
                    }
                    else if (direction == "Left")
                    {
                        vel.x = 100*SPEED;
                    }
                    else if (direction == "Above")
                    {
                        vel.y = 100*SPEED;
                    }
                    else if (direction == "Below")
                    {
                        vel.y = -40*SPEED;
                    }  
                }
                    //std::cout<<direction<<" "<<vel.x<<" "<<vel.y<<std::endl;

                break;
                //Plataformas
            case 11:
                if (direction == "Right")
                {
                    vel.x = -SPEED;
                    motion_counter = -TIME;
                    //std::cout<<direction<<std::endl;
                }
                else if (direction == "Left")
                {
                    //Arrumar:
                    vel.x = SPEED;
                    motion_counter = TIME;
                }
                //position += sf::Vector2f(speed*vel.x / 10, speed*vel.y / 10);          
                break;
            }
            move();


        }
        void Enemy1::save(std::ofstream& file)
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
            <<motion_counter<<std::endl<<std::endl;
        }  
    }    
}

