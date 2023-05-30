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
            State(int id = -1);

            virtual ~State();

            void set_StateManager(Managers::StateManager* pSM);

            int get_id() const;

            virtual void run () = 0;
            //Deixar virtual puro e colocar uma no menu para ver se funciona no windows;
            virtual void reset() { return; }
            //Tbm tirei um ;
    };

}