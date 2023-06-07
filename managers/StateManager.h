#pragma once

#include "../states/State.h"
#include <stdexcept>   
#include <vector>

namespace Managers
{
    class StateManager
    {
        private:
            int currentState;
            std::vector<States::State*> vector_states;
            static StateManager* instance;
        public:
            StateManager ();
            ~StateManager ();

            static StateManager* get_instance();
            void set_CurrentState (int i);
            int get_CurrentStateID();
            void add_state(States::State* pState);
            void reset_current_state();
            void run();
    };
}