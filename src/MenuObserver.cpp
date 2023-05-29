#include "../observers/MenuObserver.h"
#include "../menus/Menu.h"

namespace Observers
{
    MenuObserver::MenuObserver():
    Observer()
    {
        pEM->add_menu_observer(this);
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
        //std::cout<<"Teste"<<std::endl;
        if (key_code == sf::Keyboard::Up)
            pMenu->move_up();
        if (key_code == sf::Keyboard::Down)
            pMenu->move_down();
        if (key_code == sf::Keyboard::Enter)
            pMenu->select();
        if (key_code == sf::Keyboard::Right ||key_code == sf::Keyboard::Left)
            pMenu->move_horizontally();
    }
}