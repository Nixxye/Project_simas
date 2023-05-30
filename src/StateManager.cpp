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
    }
    //N funciona
    States::State *StateManager::get_CurrentState()
    {
        return vector_states[currentState];
    }
    int StateManager::get_CurrentStateID()
    {
        return currentState;
    }
    //Tirar
    int StateManager::get_LastStateID()
    {
        return 0;
        //return pLastState->get_id();
    }
    void StateManager:: add_state(States::State* pState)
    {
        //std::cout<<"Adicionando estado "<<pState->get_id()<<std::endl;
        vector_states[pState->get_id()] = pState;
    }
    void StateManager::run()
    {
        //std::cout<<"Rodando "<<currentState<<std::endl;
        if (!vector_states[currentState])
        {
            std::cout<<"Q bonito heim "<<currentState<<std::endl;
            exit(1);
        }
        vector_states[currentState]->run();
    }

    void Managers::StateManager::reset_current_state()
    {
        //std::cout<<"Entrou"<<std::endl;
        vector_states[currentState]->reset();
    }
}
