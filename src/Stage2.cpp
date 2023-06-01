#include "../stages/Stage2.h"

namespace Stages
{
    Stage2::Stage2():
    Stage(SAVE_STAGE_2, FILE_STAGE_2, SAVE_BASE_2, 2)
    {
        
    }

    Stage2::~Stage2()
    {
    }
    void Stage2::run()
    {
        players.run();
        enemies.run();
        obstacles.run();

        colision_manager.colide();
        //else horrível
        if (pSM->get_CurrentStateID() == id_state)
            pGM->center((*players.get_first())->get_position());
        else
            pGM->reset_camera();
        players.draw();
        enemies.draw();
        obstacles.draw();
    }   
}