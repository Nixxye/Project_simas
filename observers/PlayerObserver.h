#pragma once

#include "Observer.h"
#include <map>


namespace Entes
{
    namespace Characters 
    {
        class Player;
    }    
}


namespace Observers 
{

    class PlayerObserver : public Observer 
    {
        private:
            Entes::Characters::Player* pPlayer;
            std :: map <sf::Keyboard::Key,char> PlayerKeys;

        public:
            PlayerObserver();

            ~PlayerObserver();

            void notify(sf::Keyboard::Key key_code, int pressed);

            void set_player(Entes::Characters::Player* p);

            void set_PlayerKeys (sf::Keyboard::Key right,
             sf::Keyboard::Key left, sf::Keyboard::Key up);

           
    };

}