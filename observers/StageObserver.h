#pragma once

#include "Observer.h"
#include "../managers/GraphicsManager.h"

namespace Stages 
{
    class Stage;
}

namespace Observers 
{

    class StageObserver : public Observer 
    {
        private:
            Stages :: Stage* pStage;
            int state_id;
            Managers::GraphicsManager* graphics_manager;
        public:
            StageObserver(int st_id = 0);

            ~StageObserver();

            void notify(sf::Keyboard::Key key_code);


    };

}