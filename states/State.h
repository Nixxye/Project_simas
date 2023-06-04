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
            const int id_state;

        public:
            //ID de erro é -1
            State(int id = -1);

            virtual ~State();

            void set_StateManager(Managers::StateManager* pSM);

            int get_id() const;

            virtual void execute () = 0;
            virtual void reset() {};

    };

}