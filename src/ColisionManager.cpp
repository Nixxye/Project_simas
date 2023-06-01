#include "../managers/ColisionManager.h"
//Coeficiente de restituição 
#define CR 0.65

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
            A++;

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
                    A->set_vel(sf::Vector2f(A->get_vel().x, 0.f));
                    A->collide(B, "Below");
                    A->set_grounded(true);
                }
                else
                {
                    
                    A->set_position(sf::Vector2f(posA.x, posB.y + (sizeB.y + sizeA.y)/2.f));
                    A->collide(B, "Above");
                    A->set_vel(sf::Vector2f(A->get_vel().x, 0.f));
                }
            }
            else if (fabs(d.x) - fabs(sizeA.x + sizeB.x)/2.0 > fabs(d.y) - fabs(sizeA.y + sizeB.y)/2.0)
            {
                if (posA.x < posB.x)
                {
                    A->collide(B, "Right");
                    A->set_position(sf::Vector2f(posB.x - (sizeB.x + sizeA.x)/2.f, posA.y));
                    A->set_vel(sf::Vector2f(-CR*A->get_vel().x, A->get_vel().y));  
                }
                else
                {
                    A->collide(B, "Left");
                    A->set_position(sf::Vector2f(posB.x + (sizeB.x + sizeA.x)/2.f, posA.y));
                    A->set_vel(sf::Vector2f(-CR*A->get_vel().x, A->get_vel().y));  
                }
            }
        }
    }
    void ColisionManager::collide_attack(Entes::Characters::Player* Attacker, std::string direction)
    {
        //std::cout<<"Entrou"<<std::endl;
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> B = enemy_list->get_first();

        sf::Vector2f posA = Attacker->get_attack_position(), sizeA = Attacker->get_attack_size();
        sf::Vector2f posB, sizeB;
        std::string new_direction;
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
            if ((*B)->get_alive())
            {
                posB = (*B)->get_position();
                sizeB = (*B)->get_size();

                sf::Vector2f d = posB - posA;
                if ((fabs(d.x) < (sizeA.x + sizeB.x)/2.0) && (fabs(d.y) < (sizeA.y + sizeB.y)/2.0))
                {
                    (*B)->collide(Attacker, direction);
                }
              
            }
            B++;

        }

        
    }
}
