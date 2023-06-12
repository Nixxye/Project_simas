#pragma once

#include "../managers/GraphicsManager.h"
#include "../managers/StateManager.h"

#include <iostream>
#include "Subject.h"

namespace Observers 
{
    class Observer;
}

namespace Managers
{
    class EventsManager : public Subject
    {
        private:
            GraphicsManager* pGM;
            static EventsManager* instance;
            EventsManager();
        public:
            ~EventsManager();
            static EventsManager* get_instance();
            void execute();
    };
}