#pragma once

#include "../managers/EventsManager.h"
#include "../managers/StateManager.h"

#include <SFML/Graphics.hpp>

namespace Observers 
{
    class Observer 
    {
        protected:
            Managers::EventsManager* pEM;
            Managers::StateManager*  pSM;           

        public:
            Observer();

            virtual ~Observer();
            
            virtual void notify(sf::Keyboard::Key key_code) = 0;

    };
}