#include "../stages/Stage1.h"

namespace Stages
{
    Stage1::Stage1():
    Stage(SAVE_STAGE_1, FILE_STAGE_1, SAVE_BASE_1, 1)
    {
        
    }

    Stage1::~Stage1()
    {
    }
    void Stage1::run()
    {
        //std::cout<<"Testeee"<<std::endl;

        players.run();
        enemies.run();
        obstacles.run();
        /*
        std::cout<<"Ui"<<std::endl;
        std::cout<<players.get_size()<<std::endl;
        std::cout<<enemies.get_size()<<std::endl;
        std::cout<<obstacles.get_size()<<std::endl;

        */
        colision_manager.colide();
        //std::cout<<"Colidiu"<<std::endl;
        //else horrível
        if (pSM->get_CurrentStateID() == id_state)
        {
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> it = players.get_first();
            it++;
            //std::cout<<players.get_size()<<std::endl;
            if (players.get_size()==1)
            {
                if ((*players.get_first())->get_alive())
                    pGM->center((*players.get_first())->get_position());
                else
                {
                     pSM->set_CurrentState(0); // vai ser o gameover ou stage 2
                     pGM->reset_camera();
                }
                    
            }
            else 
            {
                //printf ("%d",players.get_size());
                if ((*players.get_first())->get_alive() && (*it)->get_alive())
                    pGM->center((*it)->get_position(),(*players.get_first())->get_position());
                else if (!(*players.get_first())->get_alive() && !(*it)->get_alive()) 
                {
                    pSM->set_CurrentState(0); // mudar para o gameover ou stage 2
                    pGM->reset_camera();
                }
                else if(!(*players.get_first())->get_alive())
                    pGM->center((*it)->get_position());
                else 
                    pGM->center((*players.get_first())->get_position());
            }
        }
        else
            pGM->reset_camera();
        players.draw();
        enemies.draw();
        obstacles.draw();
    }
}
