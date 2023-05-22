
#include "Observer.h"


namespace Observers 
{

    Observer::Observer():
    active(true)
    {
        this->pEM = Managers::EventsManager::getInstance();
        this->pSM = Managers::StateManager::getInstance();
        pEM->add_observer(this);
    }

    Observer::~Observer() 
    {
        pEM->remove_observer(this);
    }

} 