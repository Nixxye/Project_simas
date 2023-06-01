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
        players.run();
        enemies.run();
        obstacles.run();

        colision_manager.colide();
        //else horrível
        if (pSM->get_CurrentStateID() == id_state)
        {
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> it = players.get_first();
            it++;

            if (players.get_size()==1)
            {
                pGM->center((*players.get_first())->get_position());
            }
            else 
            {
                //printf ("%d",players.get_size());

                pGM->center((*it)->get_position(),(*players.get_first())->get_position());
            }
        }
        else
            pGM->reset_camera();
        players.draw();
        enemies.draw();
        obstacles.draw();
    }
}
