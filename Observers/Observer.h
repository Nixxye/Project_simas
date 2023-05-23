#include "../managers/EventsManager.h"
#include "../managers/StateManager.h"
#include <SFML/Graphics.hpp>
#pragma once

namespace Observers 
{
    class Observer 
    {
        protected:
            Managers::EventsManager* pEM;
            Managers::StateManager*  pSM;           
            bool active;
        public:
            Observer();

            virtual ~Observer();
            
            virtual void notify(sf::Keyboard::Key key_code) = 0;

            bool is_active () {return active;}

            void set_active (bool a) {active = a;}
    };
}