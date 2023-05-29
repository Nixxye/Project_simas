#include "../menus/Menu.h"

namespace Menus
{
    Menu :: Menu(int n_buttons):
    GameObject(),
    MAX_BUTTONS(n_buttons),
    buttons(),
    selected_index(0)
    {
        /*
        pEventManager = Managers::EventsManager::get_instance();
        sf::Font* font = graphics_manager->get_font();
        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            buttons[i].setFont(*font);
            buttons[i].setFillColor(sf::Color::White);
            buttons[i].setPosition(sf::Vector2f(WIDTH / 2, HEIGHT / (MAX_BUTTONS + 2) * 2));
        }
        pMenuObserver = new Observers::MenuObserver;
        pMenuObserver->set_menu(this);
        */
    }
    Menu :: ~Menu()
    {
        if (pMenuObserver)
            delete pMenuObserver;
        pMenuObserver = nullptr;
    }
    void Menu :: draw()
    {
        /*
        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            //arrumar a função de draw do graphics_manager
            graphics_manager->draw(&buttons[i]);
        }
        */
    } 
    void Menu :: move_up()
    {
        if (selected_index > 0)
        {
            buttons[selected_index].setFillColor(sf::Color::White);
            selected_index--;
            buttons[selected_index].setFillColor(sf::Color::Red);
        }
    }
    void Menu :: move_down()
    {
        if (selected_index < MAX_BUTTONS - 1) 
        {
            buttons[selected_index].setFillColor(sf::Color::White);
            selected_index++;
            buttons[selected_index].setFillColor(sf::Color::Red);
        }
    }
    void Menu :: run()
    {
        pEventManager->run();
        //draw();
    }
}
