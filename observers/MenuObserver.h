#pragma once 

#include "../observers/Observer.h"


namespace Menus
{
    class MainMenu;
}

namespace Observers
{
    class MenuObserver: public Observer
    {
    private:
        Menus::MainMenu* pMenu;
    public:
        MenuObserver();
        ~MenuObserver();
        void notify(sf::Keyboard::Key key_code);
        void set_menu(Menus::MainMenu *pM) { pMenu = pM; }
    };
}