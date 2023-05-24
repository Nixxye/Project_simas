#include "StateManager.h"

namespace Managers
{
     StateManager* StateManager::instance = nullptr;
    
    StateManager* StateManager::get_instance() 
    {
        if (instance == nullptr) 
        {
            instance = new StateManager();
        }
        return instance;
    }

    StateManager::StateManager()
    {


    }
    StateManager::~StateManager()
    {


    }
    void StateManager::set_CurrentState(int i)
    {
        pLastState = pCurrentState;
        pCurrentState = vector_states[i];
    }
    States::State *StateManager::get_CurrentState()
    {
        return pCurrentState;
    }
    int StateManager::get_CurrentStateID()
    {
        return pCurrentState->get_id();
    }
    int StateManager::get_LastStateID()
    {
        return pLastState->get_id();
    }
    void StateManager:: add_state(States::State* pState)
    {
       vector_states [pState->get_id()] = pState;
    }

}
