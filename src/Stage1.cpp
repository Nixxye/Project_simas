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
        //Arrumar o código com o gerenciador de eventos e gráfico:
        //Feio, horrível, pavoroso, tira daqui!
        //events_manager->run();
        players.run();
        enemies.run();
        obstacles.run();

        colision_manager.colide();
        //else horrível
        if (pSM->get_CurrentStateID() == id_state)
        {
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> it = players.get_first();
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> it2 = it++;
            it = players.get_first();
            if (players.get_size()==1)
            {
                graphics_manager->center((*it)->get_position());
            }
            else 
            {
                //printf ("%d",players.get_size());

                graphics_manager->center((*it)->get_position(),(*it2)->get_position());
            }
        }
        else
            graphics_manager->reset_camera();
        players.draw();
        enemies.draw();
        obstacles.draw();
    }
    void Stage1::create_enemies()
    {
    }
    void Stage1::create_obstacles()
    {
    }
}
