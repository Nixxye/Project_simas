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
            std::list <Observers::Observer*> player_observers;
            int state_id;
            Managers::GraphicsManager* graphics_manager;
        public:
            StageObserver(int st_id = 0);

            ~StageObserver();

            void set_stage (Stages :: Stage* pS);

            void notify(sf::Keyboard::Key key_code);

            void add_player_observer(Observers::Observer* p_o);

    };

}