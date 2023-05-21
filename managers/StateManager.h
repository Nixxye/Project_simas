#pragma once

namespace Managers
{
    class StateManager
    {
        public:
            StateManager ();
            ~StateManager ();
            void set_current_state (int i);
            State* get_current_state ();
            int get_current_state_id();
        private:
            State* pCurrent_State;
    };
}