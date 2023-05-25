#pragma once

#include "../managers/EventsManager.h"
#include "../managers/StateManager.h"

#include <SFML/Graphics.hpp>
using namespace Managers;
namespace Observers 
{
    class Observer 
    {
        protected:
            EventsManager* pEM;
            StateManager*  pSM;           

        public:
            Observer();

            virtual ~Observer();
            
            virtual void notify(sf::Keyboard::Key key_code, int pressed) = 0;

    };
}