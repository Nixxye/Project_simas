#pragma once

#include "../managers/EventsManager.h"
#include "../managers/StateManager.h"
#include "../managers/GraphicsManager.h"

#include <SFML/Graphics.hpp>

namespace Observers 
{
    class Observer 
    {
        protected:
            Managers::EventsManager* pEM;
            Managers::StateManager*  pSM;
            Managers::GraphicsManager*  pGM;

        public:
            Observer();
            virtual ~Observer();
            
            virtual void update(sf::Keyboard::Key key_code) = 0;

    };
}