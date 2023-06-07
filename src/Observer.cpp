#include "../observers/Observer.h"


namespace Observers 
{
    Observer::Observer()
    {
        this->pEM = Managers::EventsManager::get_instance();
        this->pSM = Managers::StateManager::get_instance();
    }

    Observer::~Observer() 
    {
        pEM->detach(this);
    }
} 