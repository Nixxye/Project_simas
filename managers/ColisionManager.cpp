#include "../managers/ColisionManager.h"
#include "ColisionManager.h"
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
        List<Entity> aux;
        List<Entity>::Iterator<Entity> A = player_list->get_first(),B = enemy_list->get_first();
        while (A != nullptr)
        {
            (*A)->set_grounded(false);
            while(B != nullptr)
            {
                check_colision(*A, *B);
                B++;
            }
            B = obstacle_list->get_first();
            while (B != nullptr)
            {
                check_colision(*A, *B);
                B++;
            }
            A++;
        }
        A = enemy_list->get_first();
        while (A != nullptr)
        {
            B = obstacle_list->get_first();
            (*A)->set_grounded(false);
            while(B != nullptr)
            {
                check_colision(*A, *B);
                B++;
            }
            A++;
        }
    }
    void ColisionManager::check_colision(Entity* A, Entity* B)
    {
        sf::Vector2f posA = A->get_position(), posB = B->get_position(), sizeA = A->get_size(), sizeB = B->get_size();
        sf::Vector2f d = posB - posA;
        if ((fabs(d.x) < (sizeA.x + sizeB.x)/2.0) && (fabs(d.y) < (sizeA.y + sizeB.y)/2.0))
        {
            if (fabs(d.x) - fabs(sizeA.x + sizeB.x)/2.0 < fabs(d.y) - fabs(sizeA.y + sizeB.y)/2.0)
            {
                B->set_vel(sf::Vector2f(-B->get_vel().x, -B->get_vel().y));
                if (posA.y < posB.y)
                {
                    A->set_position(sf::Vector2f(posA.x, posB.y - (sizeB.y + sizeA.y)/2.f));
                    A->set_vel(sf::Vector2f(A->get_vel().x, 0.f));
                    A->set_grounded(true);
                }
                else
                {
                    A->set_position(sf::Vector2f(posA.x, posB.y + (sizeB.y + sizeA.y)/2.f));
                    A->set_vel(sf::Vector2f(A->get_vel().x, 0.f));
                }
            }
            else if (fabs(d.x) - fabs(sizeA.x + sizeB.x)/2.0 > fabs(d.y) - fabs(sizeA.y + sizeB.y)/2.0)
            {
                if (posA.x < posB.x)
                {
                    A->set_position(sf::Vector2f(posB.x - (sizeB.x + sizeA.x)/2.f, posA.y));
                    A->set_vel(sf::Vector2f(-CR*A->get_vel().x, A->get_vel().y));  
                }
                else
                {
                    A->set_position(sf::Vector2f(posB.x + (sizeB.x + sizeA.x)/2.f, posA.y));
                    A->set_vel(sf::Vector2f(-CR*A->get_vel().x, A->get_vel().y));  
                }
            }
        }
    }
}
