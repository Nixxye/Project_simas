#pragma once 

#include "../observers/Observer.h"
#include <map>

namespace Menus
{
    class GameOver;
}

namespace Observers
{
    class GameOverObserver: public Observer
    {
    private:
        Menus::GameOver* pGO;
        std :: map <sf::Keyboard::Key,std::string> keys;
    public:
        GameOverObserver();
        ~GameOverObserver();
        void notify(sf::Keyboard::Key key_code);
        void set_menu(Menus::GameOver *p) { pGO = p; }
    };
}