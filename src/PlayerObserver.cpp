#include "../observers/PlayerObserver.h"
#include "../entities/Player.h"

namespace Observers 
{

    PlayerObserver::PlayerObserver(int i):
    Observer()
    {
        pEM->add_observer(this);
        if (i == 1)
        {
            PlayerKeys [sf::Keyboard::A] = 'L';
            PlayerKeys [sf::Keyboard::D] = 'R';
            PlayerKeys [sf::Keyboard::W] = 'U'; 
            PlayerKeys [sf::Keyboard::Space] = 'A';
        }
        if (i == 2)
        {
            PlayerKeys [sf::Keyboard::Left] = 'L';
            PlayerKeys [sf::Keyboard::Right] = 'R';
            PlayerKeys [sf::Keyboard::Up] = 'U'; 
            PlayerKeys [sf::Keyboard::Enter] = 'A';
        }
    }

    PlayerObserver::~PlayerObserver() 
    {
        pPlayer = nullptr;
    }
    void PlayerObserver :: set_player (Entes::Characters::Player* p)
    {
        pPlayer = p;
    }
    void PlayerObserver :: set_PlayerKeys (sf::Keyboard::Key key_right, sf::Keyboard::Key key_left, sf::Keyboard::Key key_up, sf::Keyboard::Key attack)
    {
        PlayerKeys [key_right] = 'R';
        PlayerKeys [key_left] = 'L';
        PlayerKeys [key_up] = 'U';
        PlayerKeys [attack] = 'A';
    }
    void PlayerObserver :: notify (sf::Keyboard::Key key_code)
    {
        std::map <sf::Keyboard::Key,char> :: iterator it = PlayerKeys.find(key_code);
       /* if (it == PlayerKeys.end())
            return; 
        if (pSM->get_CurrentStateID() != 1 && pSM->get_CurrentStateID() != 2)
            return;
        if (it->second == 'A')
            pPlayer->attack();
       pPlayer->move(it->second);*/
    }

} 