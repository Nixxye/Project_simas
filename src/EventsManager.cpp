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

    EventsManager :: EventsManager ():
    Subject()
    {
        pGM = GraphicsManager::get_instance();
    }
    EventsManager :: ~EventsManager ()
    {

    }
    void EventsManager :: execute ()
    {
        sf::Event event;
        while (pGM->get_window()->pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
                notify((event.key.code));
            else if (event.type == sf::Event::Closed)
                pGM->close_window();
        }
    }
} 