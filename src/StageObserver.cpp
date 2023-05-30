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
        pEM->add_observer(this);
    }
    StageObserver :: ~StageObserver ()
    {
        pStage == nullptr;
    }
    void StageObserver :: set_stage (Stages :: Stage* pS)
    {
        pStage = pS;
    }
    void StageObserver :: notify (sf::Keyboard::Key key_code)
    {
        //std::cout<<"Entrou "<<pSM->get_CurrentStateID()<<" "<< state_id<<std::endl;
        if (pSM->get_CurrentStateID() != state_id)
            return;
        if (sf::Keyboard::Escape == key_code)
        {
            pSM->set_CurrentState(0);
            graphics_manager->reset_camera();
        }    
        else
        {
            //std::cout<<key_code<<std::endl;
            for (std::list <Observers::Observer*> :: iterator it = player_observers.begin(); it != player_observers.end(); it++)
            {
                (*it)->notify(key_code);
            }    
        }           
    }
    void StageObserver :: add_player_observer(Observers::Observer* p_o)
    {
        player_observers.push_back(p_o);
    }

}

    