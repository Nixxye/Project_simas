#include "../managers/StateManager.h"
//para testes
#include <iostream>

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

    StateManager::StateManager():
    currentState(0)
    {
        //tamanho 5 por enquanto.
        vector_states.resize(5);
    }
    StateManager::~StateManager()
    {
        for (int i = 0; i < vector_states.size();i++)
        {
            delete vector_states[i];
        }

    }
    void StateManager::set_CurrentState(int i)
    {
        currentState = i;
    }

    int StateManager::get_CurrentStateID()
    {
        return currentState;
    }

    void StateManager:: add_state(States::State* pState)
    {
        try 
        {
            vector_states.at(pState->get_id()) = pState;
        }
        catch (const std::out_of_range& oor) 
        {
            std::cerr << "Out of Range error: " << oor.what() << '\n';
        }
    }

    void StateManager::reset_current_state()
    {
        vector_states[currentState]->reset();
    }
    void StateManager::run()
    {
        vector_states[currentState]->execute();
    }
}
