#include "../observers/Observer.h"


namespace Observers 
{
    Observer::Observer()
    {
        this->pEM = Managers::EventsManager::get_instance();
        this->pSM = Managers::StateManager::get_instance();
        pEM->add_observer(this);
    }

    Observer::~Observer() 
    {
        pEM->remove_observer(this);
    }
} 