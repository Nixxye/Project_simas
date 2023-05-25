#include "PlayerObserver.h"
#include "../entities/Player.h"

namespace Observers 
{

    PlayerObserver::PlayerObserver():
    Observer()
    {
        PlayerKeys [sf::Keyboard::A] = 'L';
        PlayerKeys [sf::Keyboard::D] = 'R';
        PlayerKeys [sf::Keyboard::W] = 'U'; 
    }

    PlayerObserver::~PlayerObserver() 
    {
        pPlayer = nullptr;
    }
    void PlayerObserver :: set_player (Entes::Characters::Player* p)
    {
        pPlayer = p;
    }
    void PlayerObserver :: set_PlayerKeys (sf::Keyboard::Key key_right, sf::Keyboard::Key key_left, sf::Keyboard::Key key_up)
    {
        PlayerKeys [key_right] = 'R';
        PlayerKeys [key_left] = 'L';
        PlayerKeys [key_up] = 'U';
    }
    void PlayerObserver :: notify (sf::Keyboard::Key key_code, int pressed)
    {
        std::map <sf::Keyboard::Key,char> :: iterator it = PlayerKeys.find(key_code);
        if (it == PlayerKeys.end())
            return; 
        pPlayer->move(it->second, pressed);
        //std::cout<<it->second<<std::endl;
    }

} 