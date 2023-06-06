#pragma once

#include "../managers/GraphicsManager.h"
#include "../managers/StateManager.h"

//#include "../entities/Player.h"

//#include "../menu/Menu.h"

//incluído para testes:
#include <iostream>
#include <list>

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
            EventsManager();
        public:
            ~EventsManager();
            
            static EventsManager* get_instance();
            void remove_observer(Observers::Observer* pObserver);
            void add_observer (Observers::Observer* pObserver);
            void execute ();
    };
}