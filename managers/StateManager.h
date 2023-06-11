#pragma once

#include "../states/State.h"
#include <stdexcept>   
#include <vector>
/*States:
0: Menu principal;
1: Fase 1 com 1 player;
2: Fase 2 com 1 player;
3: GameOver;
4: Ranking;
5: Fase 2 com 2 players;
6: Fase 1 com 2 players;
7: End;
*/
namespace Managers
{
    class StateManager
    {
        private:
            int currentState;
            std::vector<States::State*> vector_states;
            static StateManager* instance;
            StateManager ();            
        public:
            ~StateManager ();

            static StateManager* get_instance();
            void set_CurrentState (int i);
            int get_CurrentStateID();
            void add_state(States::State* pState);
            void reset_current_state();
            void execute();
    };
}