#include "../states/State.h"

#include "../managers/StateManager.h"



namespace States 
{

    Managers::StateManager *State::pSM(Managers::StateManager::get_instance());

    State::State(int id):
    id_state(id)
    {
        pSM->add_state(this);
    }

    State::~State() 
    {
        pSM = nullptr;
    }

    void State::set_StateManager(Managers::StateManager* p) 
    {
        pSM = p;
    }

    int State::get_id() const 
    {
        return id_state;
    }
    const bool State::get_active()
    {
        return (id_state == pSM->get_CurrentStateID() ? true : false);
    }

} 