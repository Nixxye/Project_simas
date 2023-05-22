
#pragma once

namespace Managers 
{
    class StateManager;
}
namespace States 
{

    class State 
    {

        protected:
            Managers :: StateManager* pSM;
            int id_state;

        public:
            State(int id);

            virtual ~State();

            void set_StateManager(Managers ::StateManager* pSM);

            int get_id() const;

    };

}