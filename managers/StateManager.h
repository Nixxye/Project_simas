
namespace Managers {
    class StateManager
    {
        private:
            State* pCurrent_State;

        public:
            StateManager ();
            ~StateManger ();
            void set_current_state (int i);
            State* get_current_state ();
            int get_current_state_id();



    };
}