#include "State.h"

#include "../managers/StateManager.h"

namespace States 
{
    State::State(int id):
    id_state(id) 
    {

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

} 