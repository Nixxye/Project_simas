#include "../managers/ColisionManager.h"
#include "ColisionManager.h"
//Coeficiente de restituição 
#define CR 0.65

namespace Managers
{
    ColisionManager::ColisionManager():
    enemy_list(), player_list(), obstacle_list()
    {

    }
    ColisionManager::~ColisionManager()
    {

    }
    void ColisionManager::colide()
    {
        List<Entity> aux;
        List<Entity>::Element<Entity>* A = player_list.get_first(),* B = enemy_list.get_first();
        while (A)
        {
            A->get_data()->set_grounded(false);
            while(B)
            {
                check_colision(A->get_data(), B->get_data());
                B = B->get_next();
            }
            B = obstacle_list.get_first();
            while (B)
            {
                check_colision(A->get_data(), B->get_data());
                B = B->get_next();
            }
            A = A->get_next();
        }
        A = enemy_list.get_first();
        while (A)
        {
            B = obstacle_list.get_first();
            A->get_data()->set_grounded(false);
            while(B)
            {
                check_colision(A->get_data(), B->get_data());
                B = B->get_next();
            }
            A = A->get_next();
        }
    }
    void ColisionManager::check_colision(Entity* A, Entity* B)
    {
        sf::Vector2f posA = A->get_position(), posB = B->get_position(), sizeA = A->get_size(), sizeB = B->get_size();
        sf::Vector2f d = posB - posA;
        //sf::Vector2f aux = Vector2f(0.f, 0.f);
        if ((fabs(d.x) < (sizeA.x + sizeB.x)/2.0) && (fabs(d.y) < (sizeA.y + sizeB.y)/2.0))
        {
            //cout<<"EPAAAAA"<<endl;
            A->troca_cor();
            B->troca_cor();
            //cout<<posA.x<<" "<<posA.y<<" "<<posB.x<<" "<<posB.y<<" "<<d.x<<" "<<d.y<<endl;
            //VERTICAL COLISION
            //below the player
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

    /*
    void ColisionManager::aux_col(Entity* A, Entity* B)
    {
        //VERTICAL COLISION:
        //bellow the player
        float xpA = A->get_position().x, ypA = A->get_position().y, xpB = B->get_position().x, ypB = B->get_position().y;
        float xsA = A->get_size().x, ysA = A->get_size().y, xsB = B->get_size().x , ysB = B->get_size().y;
        if (ypA + ysA > ypB && ypA < ypB + ysB && ((xpA < xpB+xsB && xpA > xpB)||(xpA+xsA < xpB+xsB && xpA+xsA > xpB)||(xpA > xpB+xsB && xpA < xpB)))
        {
            A->set_position(sf::Vector2f(A->get_position().x, ypB-ysA));
            A->set_vel(sf::Vector2f(A->get_vel().x, 0.f));
            A->set_grounded(true);
            //cout<<"EPAAAAA"<<endl;
            A->troca_cor();
            B->troca_cor();
            cout<<ypB-ysA<<" "<<ypB<<" "<< ypA<<endl;
        }
    }
    */
}
