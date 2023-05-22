#include "../States/State.h"
#include <vector>

#pragma once

namespace Managers
{
    class StateManager
    {
        private:
            States :: State* pCurrentState;
            States :: State* pLastState;
            std::vector< States::State*> vector_states;

        public:
            StateManager ();
            ~StateManager ();
            void set_CurrentState (int i);
            States :: State* get_CurrentState ();
            int get_CurrentStateID();
            int get_LastStateID();
            void add_state(States::State* pState);

    };
}