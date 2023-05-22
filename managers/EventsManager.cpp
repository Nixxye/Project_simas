#include "EventsManager.h"
#include "../Observers/Observer.h"


namespace Managers 
{

    EventsManager* EventsManager::instance = nullptr;


    EventsManager* EventsManager::get_instance() 
    {
        if (instance == nullptr) 
        {
            instance = new EventsManager();
        }
        return instance;
    }

    EventsManager :: EventsManager ()
    {

    }
    EventsManager :: ~EventsManager ()
    {


    }
    void  EventsManager :: add_observer(Observers::Observer* pObserver)
    {
        list_observers.push_back(pObserver);
    }
    void  EventsManager :: remove_observer(Observers::Observer* pObserver)
    {
        list_observers.remove(pObserver);
    }
  
    void EventsManager :: run()
    {
        sf::Event event;
        while (pGM->get_window()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGM->close_window();
            else if (event.type == sf::Event::KeyPressed)
            {
                for (it = list_observers.begin(); it != list_observers.end(); it++)
                {
                    if ((*it)->is_active())
                        (*it)->notify(event.key.code);
                }

            }
        }
    }
} 
