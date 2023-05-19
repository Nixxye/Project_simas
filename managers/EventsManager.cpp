#include "EventsManager.h"


namespace Managers {
    EventsManager :: EventsManager ()
    {

    }
    EventsManager :: ~EventsManager()
    {


    }
    void EventsManager :: move_players (sf::Keyboard::Key key_code)
    {
        char direction = '0';
        if (key_code  == sf::Keyboard::Space)
        {
            direction = 'U';
        }
        else if (key_code  == sf::Keyboard::A)
        {
            direction = 'L';
        }
        else if (key_code  == sf::Keyboard::D)
        {
            direction = 'R';
        }

        if (direction !=  '0' && pPlayer1 != nullptr)
        {
            pPlayer1-> move(direction);
            return;
        }

        if (key_code  == sf::Keyboard::Up)
        {
            direction = 'U';
        }
        else if (key_code  == sf::Keyboard::Right)
        {
            direction = 'R';
        }
        else if (key_code  == sf::Keyboard::Left)
        {
            direction = 'L';
        }
        if (direction !=  '0' && pPlayer2 != nullptr)
        {
            pPlayer2-> move(direction);
        }

    }
    void EventsManager :: notify_menu( sf::Keyboard::Key key_code, Menu* menu)
    {
        if (key_code  == sf::Keyboard::Up)
        {
            //menu->select_up();
        } 
        else if (key_code  == sf::Keyboard::Down)
        {
			//menu->select_down();
        } 
        else if (key_code  == sf::Keyboard::Enter) 
        {
			//menu->run();
        }
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
                int state = pSM->get_current_state_id();
                if (state == 0)
                {
                    notify_menu (event.key.code,pMainMenu);
                }
                else if (state == 1)
                {
                    if (event.key.code == sf::Keyboard:: Escape)
                    {   
                        pSM->set_current_state(PAUSE_MENU);
                    }
                    else
                    {
                        move_players(event.key.code);
                    }
   
                }
                else if (state == 2)
                {
                    notify_menu(event.key.code, pPauseMenu);
                }

            }
    }
}
} 
