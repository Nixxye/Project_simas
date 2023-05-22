#pragma once

#include "Observer.h"



namespace Stages 
{
    class Stage1;
}

namespace Observers 
{

    class Stage1Observer : public Observer 
    {
        private:
            Stages :: Stage1* pStage1;

        public:
            Stage1Observer();

            ~Stage1Observer();

            void set_stage1 (Stages :: Stage1* pS);

            void notify(sf::Keyboard::Key key_code);

    };

}