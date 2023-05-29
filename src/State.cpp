#include "../states/State.h"

#include "../managers/StateManager.h"

namespace States 
{
    State::State(int id):
    id_state(id),
    pSM(Managers :: StateManager ::get_instance())
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

} 