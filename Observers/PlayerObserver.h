#pragma once

#include "Observer.h"
#include <map>


namespace Entities::Characters 
{
    class Player;
}

namespace Observers 
{

    class PlayerObserver : public Observer 
    {
        private:
            Entities::Characters::Player* pPlayer;
            std :: map <sf::Keyboard::Key,char> PlayerKeys;

        public:
            PlayerObserver();

            ~PlayerObserver();

            void notify(sf::Keyboard::Key key_code);

            void set_player(Entities::Characters::Player* p);

            void set_PlayerKeys (sf::Keyboard::Key right, sf::Keyboard::Key left, sf::Keyboard::Key up);

           
    };

}