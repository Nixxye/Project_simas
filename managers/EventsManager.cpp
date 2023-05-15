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
                if (pMenu->is_active())
                {
                    //TODO
                }
                if (!(pMenu->is_active()))
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        pPlayer1->move('U');
                    }
                    else if (event.key.code == sf::Keyboard::D)
                    {
                        pPlayer1->move('L');
                    }
                    else if (event.key.code == sf::Keyboard::A)
                    {
                        pPlayer1->move('R');
                    }


                    else if (event.key.code == sf::Keyboard::Up)
                    {
                        pPlayer2->move('U');
                    }
                    else if (event.key.code == sf::Keyboard::Left)
                    {
                        pPlayer2->move('L');
                    }
                    else if (event.key.code == sf::Keyboard::Right)
                    {
                        pPlayer2->move('R');
                    }
                }
            }

         }
    }
}
    
