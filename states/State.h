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
            //ID de erro é -1
            State(int id = -1);

            virtual ~State();

            void set_StateManager(Managers::StateManager* pSM);

            int get_id() const;

            virtual void run () = 0;

    };

}