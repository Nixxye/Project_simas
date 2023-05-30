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
            graphics_manager->center((*players.get_first())->get_position());
        else
            graphics_manager->reset_camera();
        players.draw();
        enemies.draw();
        obstacles.draw();
    }
}
