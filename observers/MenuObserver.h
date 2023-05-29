#pragma once 

#include "../observers/Observer.h"


namespace Menus
{
    class Menu;
}

namespace Observers
{
    class MenuObserver: public Observer
    {
    private:
        Menus::Menu* pMenu;
    public:
        MenuObserver();
        ~MenuObserver();
        void notify(sf::Keyboard::Key key_code);
        void set_menu(Menus::Menu *pM) { pMenu = pM; }
    };
}