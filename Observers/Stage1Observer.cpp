#include "Stage1Observer.h"

namespace Observers 
{
    Stage1Observer :: Stage1Observer ():
    Observer ()
    {

    }
    Stage1Observer :: ~Stage1Observer ()
    {
        pStage1 == nullptr;
    }
    void Stage1Observer :: set_stage1 (Stages :: Stage1* pS)
    {
        pStage1 = pS;
    }
    void Stage1Observer :: notify (sf::Keyboard::Key key_code)
    {

            if (sf::Keyboard::A == key_code)
            { }
                //pSM->set_CurrentState (0
    }

}

    