#include "../observers/MenuObserver.h"
#include "../menus/MainMenu.h"

namespace Observers
{
    MenuObserver::MenuObserver():
    Observer()
    {
        //pEM->attach(this);
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
        if (pSM->get_CurrentStateID() == 1 || pSM->get_CurrentStateID() == 2 ||
        pSM->get_CurrentStateID() == 5 || pSM->get_CurrentStateID() == 6)
        {
            if (key_code == sf::Keyboard::Escape)
            {
                pSM->set_CurrentState(0);
                pGM->reset_camera();
                return;
            }
        }
        if (pSM->get_CurrentStateID() != 0)
            return;
        //std::cout<<"Teste"<<std::endl;
        else if (key_code == sf::Keyboard::Up)
            pMenu->move_up();
        else if (key_code == sf::Keyboard::Down)
            pMenu->move_down();
        else if (key_code == sf::Keyboard::Enter)
            pMenu->select();
        else if (key_code == sf::Keyboard::Right ||key_code == sf::Keyboard::Left)
            pMenu->move_horizontally(1);
        else if (key_code == sf::Keyboard::LControl||key_code == sf::Keyboard::RControl)
            pMenu->move_horizontally(2);
        
    }
}