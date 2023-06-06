#include "../stages/Stage2.h"

namespace Stages
{
    Stage2::Stage2():
    Stage(SAVE_STAGE_2, FILE_STAGE_2, SAVE_BASE_2, 2)
    {
        texture = pGM->load_textures("../assets/stage2.png");
        body.setTexture(texture);     
    }

    Stage2::~Stage2()
    {
    }
    void Stage2::execute()
    {
    
                //std::cout<<"Testeee"<<std::endl;
        //draw();// Nao sei pq nao desenha o ataque
        players.execute();
        enemies.execute();
        obstacles.execute();

        colision_manager.colide();
        //draw();
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
                     pSM->set_CurrentState(3); // vai ser o gameover ou stage 2
                     pGM->reset_camera();
                }
                    
            }
            else 
            {
                //printf ("%d",players.get_size());
                if ((*players.get_first())->get_alive() && (*it)->get_alive())
                    pGM->center((*it)->get_position(),(*players.get_first())->get_position());
                else if (!(*players.get_first())->get_alive() && !(*it)->get_alive()) 
                    pSM->set_CurrentState(3); // mudar para o gameover
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