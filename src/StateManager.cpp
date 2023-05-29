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


    }
    void StateManager::set_CurrentState(int i)
    {
        currentState = i;
        //pLastState = pCurrentState;
        //pCurrentState = vector_states[i];
    }
    States::State *StateManager::get_CurrentState()
    {
        return vector_states[currentState];
        //return pCurrentState;
    }
    int StateManager::get_CurrentStateID()
    {
        return 0;
        //return pCurrentState->get_id();
    }
    int StateManager::get_LastStateID()
    {
        return 0;
        //return pLastState->get_id();
    }
    void StateManager:: add_state(States::State* pState)
    {
       vector_states[pState->get_id()] = pState;
    }
    void StateManager::run()
    {
        //std::cout<<"Rodando "<<currentState<<std::endl;
        if (!vector_states[currentState])
        {
            std::cout<<"Q bonito heim"<<std::endl;
            exit(1);
        }
        vector_states[currentState]->run();
    }
}
