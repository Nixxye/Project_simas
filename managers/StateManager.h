#pragma once

#include "../states/State.h"
#include <vector>

namespace Managers
{
    class StateManager
    {
        private:
            int currentState;
            //States :: State* pCurrentState;
            //States :: State* pLastState;
            std::vector<States::State*> vector_states;
            static StateManager* instance;
        public:
            StateManager ();
            ~StateManager ();

            static StateManager* get_instance();
            void set_CurrentState (int i);
            States :: State* get_CurrentState ();
            int get_CurrentStateID() { return currentState; }
            void add_state(States::State* pState);

            void run();
            void reset_current_state();
    };
}