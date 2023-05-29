#include "../managers/EventsManager.h"
#include "../observers/Observer.h"


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
        pGM = GraphicsManager::get_instance();

        list_keys.push_back(sf::Keyboard::A);
        list_keys.push_back(sf::Keyboard::W);
        list_keys.push_back(sf::Keyboard::D);
        list_keys.push_back(sf::Keyboard::Up);
        list_keys.push_back(sf::Keyboard::Down);
        list_keys.push_back(sf::Keyboard::Enter);
        list_keys.push_back(sf::Keyboard::Escape);
    }
    EventsManager :: ~EventsManager ()
    {
        for (it = list_observers.begin(); it != list_observers.end(); it++)
        {
            delete(*it);
        }
        list_observers.clear();

    }
    void  EventsManager :: add_observer(Observers::Observer* pObserver)
    {
        list_observers.push_back(pObserver);
    }
    void  EventsManager :: add_menu_observer(Observers::Observer* pObserver)
    {
        list_menu_observers.push_back(pObserver);
    }
    void  EventsManager :: remove_observer(Observers::Observer* pObserver)
    {
        list_observers.remove(pObserver);
    }
  
    void EventsManager :: run()
    {
        sf::Event event;
        for (it_keys = list_keys.begin(); it_keys != list_keys.end();it_keys++)
        {
            if (sf::Keyboard::isKeyPressed(*it_keys))
            {
                for (it = list_observers.begin(); it != list_observers.end(); it++)
                {
                    (*it)->notify((*it_keys));
                }
            }
        }
        while (pGM->get_window()->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                for (it = list_menu_observers.begin(); it != list_menu_observers.end(); it++)
                {
                    (*it)->notify((event.key.code));
                } 
            }
            if (event.type == sf::Event::Closed)
                pGM->close_window();
        }
    }
} 