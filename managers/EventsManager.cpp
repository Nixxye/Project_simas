#include "EventsManager.h"


namespace Managers {
    EventsManager :: EventsManager ()
    {

    }
    EventsManager :: ~EventsManager()
    {

    }
    void EventsManager :: run ()
    {
        sf::Event event;
        while (pGM->get_window()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                pGM->close_window();
            else if (event.type == sf::Event::KeyPressed)
            {
                 if (event.key.code == sf::Keyboard::Escape)
                 {
                     pPlayer->move('U');
                 }
                 else if (event.key.code == sf::Keyboard::D)
                 {
                    pPlayer->move('L');
                 }
                 else if (event.key.code == sf::Keyboard::A)
                 {
                    pPlayer->move('R');
                 }
            }

         }
    }
}
    
