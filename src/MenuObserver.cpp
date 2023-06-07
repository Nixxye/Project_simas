#include "../observers/MenuObserver.h"
#include "../menus/MainMenu.h"

namespace Observers
{
    MenuObserver::MenuObserver():
    Observer()
    {
        pEM->attach(this);
    }
    MenuObserver::~MenuObserver()
    {
        pMenu = nullptr;
    }
    void MenuObserver::update(sf::Keyboard::Key key_code)
    {
        if (!pMenu)
        {
            //std::cout<<"EITAAAAAAAAAAA"<<std::endl;
            return;
        }
        if (pSM->get_CurrentStateID() != 0)
            return;
        //std::cout<<"Teste"<<std::endl;
        if (key_code == sf::Keyboard::Up)
            pMenu->move_up();
        if (key_code == sf::Keyboard::Down)
            pMenu->move_down();
        if (key_code == sf::Keyboard::Enter)
            pMenu->select();
        if (key_code == sf::Keyboard::Right ||key_code == sf::Keyboard::Left)
            pMenu->move_horizontally(1);
        if (key_code == sf::Keyboard::Num1 ||key_code == sf::Keyboard::Num2 ||
        key_code == sf::Keyboard::Numpad1  ||key_code == sf::Keyboard::Numpad2 )
            pMenu->move_horizontally(2);
        
    }
}