#include "../observers/MenuObserver.h"

namespace Observers
{
    MenuObserver::MenuObserver():
    Observer()
    {

    }
    MenuObserver::~MenuObserver()
    {
        pMenu = nullptr;
    }
    void MenuObserver::notify(sf::Keyboard::Key key_code)
    {
        if (!pMenu)
        {
            std::cout<<"EITAAAAAAAAAAA"<<std::endl;
            return;
        }
        if (key_code == sf::Keyboard::Up)
            pMenu->move_up();
        if (key_code == sf::Keyboard::Down)
            pMenu->move_down();
        if (key_code == sf::Keyboard::Enter)
            pMenu->select();
    }
}