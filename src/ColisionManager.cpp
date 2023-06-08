#include "../managers/ColisionManager.h"
#include <math.h>


namespace Managers
{
    ColisionManager::ColisionManager():
    enemy_list(nullptr), player_list(nullptr), obstacle_list(nullptr)
    {

    }
    ColisionManager::~ColisionManager()
    {

    }
    void ColisionManager::colide()
    {
        Lists::List<Entes::Entity> aux;
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> A,B = enemy_list->get_first();
        
        for (A = player_list->get_first(); A != nullptr; A++)
        {
            if ((*A)->get_alive())
            {
                (*A)->set_grounded(false);
                while(B != nullptr)
                {
                    if ((*B)->get_alive())
                        check_colision(*A, *B);
                    B++;
                }
                B = obstacle_list->get_first();
                while (B != nullptr)
                {
                    if ((*B)->get_alive())
                        check_colision(*A, *B);
                    B++;
                }
            }
        }
        A = enemy_list->get_first();
        while (A != nullptr)
        {
            if ((*A)->get_alive())
            {
                B = obstacle_list->get_first();
                (*A)->set_grounded(false);
                while(B != nullptr)
                {
                    if ((*B)->get_alive())
                        check_colision(*A, *B);
                    B++;
                }                 
            }
            A++;
        }
    }
    void ColisionManager::check_colision(Entes::Entity* A, Entes::Entity* B)
    {
        sf::Vector2f posA = A->get_position(), posB = B->get_position(), sizeA = A->get_size(), sizeB = B->get_size();
        sf::Vector2f d = posB - posA;
        if ((fabs(d.x) < (sizeA.x + sizeB.x)/2.0) && (fabs(d.y) < (sizeA.y + sizeB.y)/2.0))
        {
            if (fabs(d.x) - fabs(sizeA.x + sizeB.x)/2.0 < fabs(d.y) - fabs(sizeA.y + sizeB.y)/2.0)
            {
                //B->set_vel(sf::Vector2f(-B->get_vel().x, -B->get_vel().y));
                if (posA.y < posB.y)
                {
                    A->set_position(sf::Vector2f(posA.x, posB.y - (sizeB.y + sizeA.y)/2.f));
                    A->collide(B, "Below");
                    B->collide(A, "Above");
                    A->set_grounded(true);
                }
                else
                {    
                    A->set_position(sf::Vector2f(posA.x, posB.y + (sizeB.y + sizeA.y)/2.f));
                    A->collide(B, "Above");
                    B->collide(A, "Below");
                }
            }
            else if (fabs(d.x) - fabs(sizeA.x + sizeB.x)/2.0 > fabs(d.y) - fabs(sizeA.y + sizeB.y)/2.0)
            {
                if (posA.x < posB.x)
                {
                    A->collide(B, "Right");
                    B->collide(A, "Left");
                    A->set_position(sf::Vector2f(posB.x - (sizeB.x + sizeA.x)/2.f, posA.y)); 
                }
                else
                {
                    A->collide(B, "Left");
                    B->collide(A, "Right");
                    A->set_position(sf::Vector2f(posB.x + (sizeB.x + sizeA.x)/2.f, posA.y));
                }
            }
        }
    }
    void ColisionManager::collide_attack(Entes::Characters::Player* Attacker, std::string direction)
    {
        //int return_value = 0;
        //std::cout<<"No collide-attack"<<std::endl;
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> bullet;
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> B = enemy_list->get_first();
        sf::Vector2f posA = Attacker->get_attack_position(), sizeA = Attacker->get_attack_size();
        sf::Vector2f d_bullet;
        sf::Vector2f posB, sizeB;
        std::string new_direction;
        //std::cout<<sizeA.x<<" "<<sizeA.y<<" "<<posA.x<<" "<<posA.y<<std::endl;
        if (direction == "Above")
            new_direction = "Below";
        else if (direction == "Below")
            new_direction = "Above";
        else if (direction == "Left")
            new_direction = "Right";
        else if (direction == "Right")
            new_direction = "Left";

        while (B != nullptr)
        {
            //std::cout<<"No Loop"<<std::endl;
            if ((*B)->get_alive())
            {
                posB = (*B)->get_position();
                sizeB = (*B)->get_size();
                
                sf::Vector2f d = posB - posA;
                if ((fabs(d.x) < (sizeA.x + sizeB.x)/2.0) && (fabs(d.y) < (sizeA.y + sizeB.y)/2.0))
                {
                    //return_value++;
                    (*B)->collide(Attacker, new_direction);
                    Attacker->collide_attack(*B, direction);
                    //Chefão:

                    //Attacker->collide(*B, direction);
                }  
                if ((*B)->get_id() == 3)
                {
                    bullet = (static_cast<Entes::Characters::Boss*>(*B))->get_bullets();
                    while (bullet != nullptr)
                    {
                        d_bullet = posA - (*bullet)->get_position();
                        if ((fabs(d_bullet.x) < (sizeA.x + sizeB.x)/2.0) && (fabs(d_bullet.y) < (sizeA.y + sizeB.y)/2.0))
                        {
                            //return_value++;
                            //std::cout<<"Colidu"<<std::endl;
                            (*bullet)->collide(Attacker, direction);
                            Attacker->collide_attack(*bullet, direction);
                            if (!static_cast<Entes::Bullet*>(*bullet)->get_friendly())
                            {
                                if (direction == "Below")
                                    attack_and_bullets(sizeA, Attacker->get_position(), sf::Vector2f(Attacker->get_vel().x, 5.f), *bullet);
                                else if (direction == "Above")
                                    attack_and_bullets(sizeA, Attacker->get_position(), sf::Vector2f(Attacker->get_vel().x, -5.f), *bullet);
                                else if (direction == "Right")
                                    attack_and_bullets(sizeA, Attacker->get_position(), sf::Vector2f(-5.f, Attacker->get_vel().x), *bullet);
                                else if (direction == "Left")
                                    attack_and_bullets(sizeA, Attacker->get_position(), sf::Vector2f(5.f, Attacker->get_vel().x), *bullet);
                            }
                                //attack_and_bullets(sizeA, Attacker->get_position(), Attacker->get_vel(), *bullet);
                        }
                        bullet++;
                    }
                }
            }
            B++;
        }
        //return return_value;        
    }
    void ColisionManager::collide_bullets(Entes::Entity* bullet)
    {
        Lists::List<Entes::Entity> aux;
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> B = player_list->get_first();
        
        if (!(static_cast<Entes::Bullet*>(bullet)->get_friendly()))
        {
            while(B != nullptr)
            {
                if ((*B)->get_alive())
                    check_colision(bullet, *B);
                B++;
            }
        }
        else 
        {
            B = enemy_list->get_first();
            while (B != nullptr)
            {
                if ((*B)->get_alive())
                    check_colision(bullet, *B);
                B++;
            }
        }

        B = obstacle_list->get_first();
        while (B != nullptr)
        {
            if ((*B)->get_alive())
                check_colision(bullet, *B);
            B++;
            
        }
    }
    //Colisão barreto;
    void ColisionManager::elastic_colision(Entes::Entity* A, Entes::Entity* B)
    {
        if (!A->get_alive() || !B->get_alive())
            return;
        sf::Vector2f posA = A->get_position(), posB = B->get_position(), sizeA = A->get_size(), sizeB = B->get_size();
        sf::Vector2f d = posB - posA;
        if (d.x <= A->get_size().x/2 + B->get_size().x/2 || d.y <= A->get_size().y/2 + B->get_size().y/2)
        {
            //Cria os eixos de colisão:
            sf::Vector2f y_axis = sf::Vector2f(A->get_position().x - B->get_position().x, A->get_position().y - B->get_position().y);
            sf::Vector2f x_axis = sf::Vector2f(y_axis.y, -y_axis.x);
            //Normaliza os eixos:
            y_axis = y_axis / sqrt(y_axis.x * y_axis.x + y_axis.y * y_axis.y);
            x_axis = x_axis / sqrt(x_axis.x * x_axis.x + x_axis.y * x_axis.y);
            //Projeta as velocidades nos novos eixos:
            sf::Vector2f vy1 = y_axis * (A->get_vel().x * y_axis.x + A->get_vel().y * y_axis.y); 
            sf::Vector2f vy2 = y_axis * (B->get_vel().x * y_axis.x + B->get_vel().y * y_axis.y);
            sf::Vector2f vx1 = y_axis * (A->get_vel().x * x_axis.x + A->get_vel().y * x_axis.y); 
            sf::Vector2f vx2 = y_axis * (B->get_vel().x * x_axis.x + B->get_vel().y * x_axis.y);
        
            sf::Vector2f vf1 = (((vy1 * A->get_mass()) + (vy2 * B->get_mass())) * (float) (1+CR) /(A->get_mass() + B->get_mass())) + vy1 * (float) (-CR);
            sf::Vector2f vf2 = (((vy1 * A->get_mass()) + (vy2 * B->get_mass())) * (float) (1+CR) /(A->get_mass() + B->get_mass())) + vy2 * (float) (-CR);

            A->set_vel(vf1 + vx1);
            A->move();
            B->set_vel(vf2 + vx2);
            B->move();
        } 
    }
    void ColisionManager::attack_and_bullets(sf::Vector2f attack_size, sf::Vector2f attack_position, sf::Vector2f player_vel, Entes::Entity* B)
    {
        //std::cout<<"Aqui chega"<<std::endl;
        sf::Vector2f posB = B->get_position(), sizeB = B->get_size();
        sf::Vector2f d = posB - attack_position;
        if (d.x <= attack_size.x/2 + B->get_size().x/2 || d.y <= attack_size.y/2 + B->get_size().y/2)
        {
            //Cria os eixos de colisão:
            sf::Vector2f y_axis = sf::Vector2f(attack_position.x - B->get_position().x, attack_position.y - B->get_position().y);
            sf::Vector2f x_axis = sf::Vector2f(y_axis.y, -y_axis.x);
            //Normaliza os eixos:
            y_axis = y_axis / sqrt(y_axis.x * y_axis.x + y_axis.y * y_axis.y);
            x_axis = x_axis / sqrt(x_axis.x * x_axis.x + x_axis.y * x_axis.y);
            //Projeta as velocidades nos novos eixos:
            sf::Vector2f vy1 = y_axis * (player_vel.x * y_axis.x + player_vel.y * y_axis.y); 
            sf::Vector2f vy2 = y_axis * (B->get_vel().x * y_axis.x + B->get_vel().y * y_axis.y);
 
            sf::Vector2f vx2 = y_axis * (B->get_vel().x * x_axis.x + B->get_vel().y * x_axis.y);
        
            //sf::Vector2f vf1 = (((vy1) + (vy2 * B->get_mass())) * (float) (1+CR) /(1 + B->get_mass())) + vy1 * (float) (-CR);
            //sf::Vector2f vf2 = (((vy1) + (vy2 * B->get_mass())) * (float) (1+CR) /(1 + B->get_mass())) + vy2 * (float) (-CR);
            sf::Vector2f vf1 = (((vy1)) * (float) (1+CR) /(1 + B->get_mass())) - vy1;
            sf::Vector2f vf2 = ((vy1) * (float) (1+CR) /(1 + B->get_mass())) - vy2;

            B->set_vel(vf2 + vx2);
            B->move();
            //std::cout<<"Eita3"<<std::endl;
        }     
    }
    void ColisionManager::collide_explosion(sf::CircleShape* explosion, float power)
    {
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> B = enemy_list->get_first();
        while (B != nullptr)
        {
            if ((*B)->get_alive())
            {
                sf::Vector2f posB = (*B)->get_position();
                sf::Vector2f sizeB = (*B)->get_size();
                
                sf::Vector2f d = posB - explosion->getPosition();
                if ((fabs(d.x) < explosion->getRadius() + sizeB.x / 2.0) && (fabs(d.y) < explosion->getRadius() + sizeB.y / 2.0))
                {
                    //elastic_colision(explosion, *B, power);
                }                
            }
            B++;
        }
        B = player_list->get_first();
        while (B != nullptr)
        {
            if ((*B)->get_alive())
            {
                sf::Vector2f posB = (*B)->get_position();
                sf::Vector2f sizeB = (*B)->get_size();
                
                sf::Vector2f d = posB - explosion->getPosition();
                if ((fabs(d.x) <= explosion->getRadius() + sizeB.x) && (fabs(d.y) <= explosion->getRadius() + sizeB.y))
                {
                    elastic_colision(explosion, *B, power);
                }                
            }
            B++;
        }
    }
    void ColisionManager::elastic_colision(sf::CircleShape* A, Entes::Entity* B, float power)
    {
        if (!B->get_alive())
            return;

        sf::Vector2f posA = A->getPosition(), posB = B->get_position(), sizeA = sf::Vector2f(A->getRadius()*2, A->getRadius()*2), sizeB = B->get_size();
        sf::Vector2f d = posB - posA;
        if (d.x <= sizeA.x/2.f + B->get_size().x/2.f || d.y <= sizeA.y/2.f + B->get_size().y/2.f)
        {
            //Cria os eixos de colisão:
            sf::Vector2f y_axis = posA - posB;

            y_axis = y_axis / sqrt(y_axis.x * y_axis.x + y_axis.y * y_axis.y);

             B->set_vel(y_axis*(-power));
        } 
        std::cout<<B->get_vel().x<<" "<<B->get_vel().y<<std::endl;
    }
}

