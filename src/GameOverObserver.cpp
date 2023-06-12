#include "../observers/GameOverObserver.h"
#include "../menus/GameOver.h"

namespace Observers
{
    GameOverObserver::GameOverObserver():
    Observer()
    {
        pEM->attach(this);

        keys [sf::Keyboard::A] = "a";
        keys [sf::Keyboard::B] = "b";
        keys [sf::Keyboard::C] = "c"; 
        keys [sf::Keyboard::D] = "d";
        keys [sf::Keyboard::E] = "e";
        keys [sf::Keyboard::F] = "f";
        keys [sf::Keyboard::G] = 'g';
        keys [sf::Keyboard::H] = "h";
        keys [sf::Keyboard::I] = "i";
        keys [sf::Keyboard::J] = "j";
        keys [sf::Keyboard::K] = "k";
        keys [sf::Keyboard::L] = "l";
        keys [sf::Keyboard::M] = "m";
        keys [sf::Keyboard::N] = "n";
        keys [sf::Keyboard::O] = "o";
        keys [sf::Keyboard::P] = "p";
        keys [sf::Keyboard::Q] = "q";
        keys [sf::Keyboard::R] = "r";
        keys [sf::Keyboard::S] = "s";
        keys [sf::Keyboard::T] = "t";
        keys [sf::Keyboard::U] = "u";
        keys [sf::Keyboard::V] = "v";
        keys [sf::Keyboard::W] = "w";
        keys [sf::Keyboard::X] = "x";
        keys [sf::Keyboard::Y] = "y";
        keys [sf::Keyboard::Z] = "z";
    }
    GameOverObserver::~GameOverObserver()
    {
        pGO = nullptr;
    }
    void GameOverObserver::update(sf::Keyboard::Key key_code)
    {
        if (pSM->get_CurrentStateID() != 3)
            return;
        if (!pGO)
        {
            return;
        }
        if (key_code == sf::Keyboard::Up)
            pGO->move_up();
        if (key_code == sf::Keyboard::Down)
            pGO->move_down();

        if (key_code == sf::Keyboard::Enter)
        {
            pGO->set_final_name();
            pGO->select();
        }
        if (key_code == sf::Keyboard::Tab)
        {
            pGO->active_name();
        }
        
        std::map <sf::Keyboard::Key,std::string> :: iterator it = keys.find(key_code);
        if (it == keys.end())
            return; 
        pGO->add_name(it->second);
    }
}