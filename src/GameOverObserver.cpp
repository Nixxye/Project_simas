#include "../observers/GameOverObserver.h"
#include "../menus/GameOver.h"

namespace Observers
{
    GameOverObserver::GameOverObserver():
    Observer()
    {
        pEM->add_menu_observer(this);

        keys [sf::Keyboard::A] = 'a';
        keys [sf::Keyboard::B] = 'b';
        keys [sf::Keyboard::C] = 'c'; 
        keys [sf::Keyboard::D] = 'd';
        keys [sf::Keyboard::E] = 'e';
        keys [sf::Keyboard::F] = 'f';
        //keys [sf::Keyboard::G] = 'g';
        keys [sf::Keyboard::H] = 'h';
        keys [sf::Keyboard::I] = 'i';
        keys [sf::Keyboard::J] = 'j';
        keys [sf::Keyboard::K] = 'k';
        keys [sf::Keyboard::L] = 'l';
        keys [sf::Keyboard::M] = 'm';
        keys [sf::Keyboard::N] = 'n';
        keys [sf::Keyboard::O] = 'o';
        keys [sf::Keyboard::P] = 'p';
        keys [sf::Keyboard::Q] = 'q';
        keys [sf::Keyboard::R] = 'r';
        keys [sf::Keyboard::S] = 's';
    }
    GameOverObserver::~GameOverObserver()
    {
        pGO = nullptr;
    }
    void GameOverObserver::notify(sf::Keyboard::Key key_code)
    {
        if (!pGO)
        {
            std::cout<<"EITAAAAAAAAAAA"<<std::endl;
            return;
        }
        std::map <sf::Keyboard::Key,char> :: iterator it = keys.find(key_code);
        if (it == keys.end())
            return; 
        pGO->set_name(it->second);
    }
}