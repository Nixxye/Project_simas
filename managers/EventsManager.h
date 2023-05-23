#include "GraphicsManager.h"
#include "StateManager.h"
#include "../entities/Player1.h"
#include "../entities/Player.h"
#include "../entities/Player2.h"
#include "../menu/Menu.h"
#include <list>

//incluído para testes:
#include <iostream>
#pragma once
using namespace std;
using namespace entes::Characters;


namespace Observers 
{
    class Observer;
}

namespace Managers
{
   class EventsManager
    {
        private:
            GraphicsManager* pGM;
            StateManager* pSM;
            std::list <Observers::Observer*> list_observers;
            std::list <Observers::Observer*> :: iterator it;



            static EventsManager* instance;
        public:
            EventsManager();
            ~EventsManager();
            EventsManager* get_instance();
            void remove_observer(Observers::Observer* pObserver);
            void add_observer (Observers::Observer* pObserver);
            void run ();
    };
}