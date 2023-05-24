#include "Observer.h"


namespace Observers 
{

    Observer::Observer()
    {
        this->pEM = EventsManager::get_instance();
        this->pSM = StateManager::get_instance();
        pEM->add_observer(this);
    }

    Observer::~Observer() 
    {
        pEM->remove_observer(this);
    }

} 