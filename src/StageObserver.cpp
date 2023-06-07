#include "../observers/StageObserver.h"
//p testes
#include <iostream>

namespace Observers 
{
    StageObserver :: StageObserver (int st_id):
    Observer (),
    state_id(st_id),
    graphics_manager(Managers::GraphicsManager::get_instance())
    {
        pEM->attach(this);
    }
    StageObserver :: ~StageObserver ()
    {
        pStage == nullptr;
    }

    void StageObserver :: update (sf::Keyboard::Key key_code)
    {
        //std::cout<<"Entrou "<<pSM->get_CurrentStateID()<<" "<< state_id<<std::endl;
        if (pSM->get_CurrentStateID() != state_id)
            return;
        if (sf::Keyboard::Escape == key_code)
        {
            pSM->set_CurrentState(0);
            graphics_manager->reset_camera();
        }    

    }

}

    