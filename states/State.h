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
            //Colocar static?
            static Managers :: StateManager* pSM;
            const int id_state;

        public:
            State(int id = -1);

            virtual ~State();

            void set_StateManager(Managers::StateManager* pSM);

            int get_id() const;

            const bool get_active();

            virtual void execute () = 0;
            virtual void reset() {};
    };

}