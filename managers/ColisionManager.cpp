#include "../managers/ColisionManager.h"
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
        auto A = player_list.get_first(), auto B = enemy_list.get_first();
        while (A)
        {
            A->set_grounded(false);
            while(B)
            {
                //aux_col(A, B);
                B = B->get_next();
            }
            B = obstacle_list.get_first();
            while (B)
            {
                aux_col(A->, B);
            }
            A = A->
        }
    }
    void ColisionManager::aux_col(Entity* A, Entity* B)
    {
        //VERTICAL COLISION:
        //bellow the player
        float xpA = A->get_position().x, ypA = A->get_position().y, xpB = B->get_position().x, ypB = B->get_position().y;
        float xsA = A->get_size().x, ysA = A->get_size().y, xsB = B->get_size().x , ysB = B->get_size().y; 
        if (ypA + ysA > ypB && ypA < ypB + ysB && ((xpA < xpB+xsB && xpA > xpB)||(xpA+xsA < xpB+xsB && xpA+xsA > xpB)||(xpA > xpB+xsB && xpA < xpB)))
        {
            A->set_position(sf::Vector2f(A->get_position().x, ypB));
            A->set_vel(sf::Vector2f(A->get_vel().x, 0.f));
            A->set_grounded(true);
            cout<<"EPAAAAA"<<endl;
        }
    }
}
