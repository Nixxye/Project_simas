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
        vector_states.resize(6);
    }
    StateManager::~StateManager()
    {


    }
    void StateManager::set_CurrentState(int i)
    {
        currentState = i;
        printf ("State:%d", currentState);
        //pLastState = pCurrentState;
        //pCurrentState = vector_states[i];
    }
    //N funciona
    States::State *StateManager::get_CurrentState()
    {
        if (!vector_states[currentState])
        {
            std::cout<<"Q feio heim"<<std::endl;
            exit(1);
        }
        return vector_states[currentState];
    }
    int StateManager::get_CurrentStateID()
    {
        return currentState;
    }
    //Tirar
    void StateManager:: add_state(States::State* pState)
    {
      //std::cout<<"OIII"<<std::endl;
       vector_states[pState->get_id()] = pState;
    }
    void StateManager::execute()
    {
        //std::cout<<"Rodando "<<currentState<<std::endl;
        if (!vector_states[currentState])
        {
            std::cout<<"Q bonito heim "<<currentState<<std::endl;
            exit(1);
        }
        vector_states[currentState]->execute();
    }

    void Managers::StateManager::reset_current_state()
    {
        vector_states[currentState]->reset();
    }
}
