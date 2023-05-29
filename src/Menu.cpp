#include "../menus/Menu.h"

namespace Menus
{
    Menu :: Menu(int n_buttons, int id):
    GameObject(),
    State(id),
    MAX_BUTTONS(n_buttons),
    buttons(),
    selected_index(0)
    {
        pEventManager = Managers::EventsManager::get_instance();
        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            buttons.push_back(new Button(sf::Vector2f(WIDTH / 2, (i + 2) *(20 + SIZEY))));
        }
        buttons[0]->change_color();
        pMenuObserver = new Observers::MenuObserver;
        pMenuObserver->set_menu(this);

    }
    Menu :: ~Menu()
    {
        if (pMenuObserver)
            delete pMenuObserver;
        
        pMenuObserver = nullptr;

        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            delete buttons[i];
        }
    }
    void Menu :: draw()
    {
        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            //arrumar a função de draw do graphics_manager
            buttons[i]->draw();
        }
    } 
    void Menu :: move_up()
    {
        if (selected_index > 0)
        {
            buttons[selected_index]->change_color();
            selected_index--;
            buttons[selected_index]->change_color();
        }
    }
    void Menu :: move_down()
    {
        if (selected_index < MAX_BUTTONS - 1) 
        {
            buttons[selected_index]->change_color();
            selected_index++;
            buttons[selected_index]->change_color();
        }
    }
    void Menu :: run()
    {
        pEventManager->run();
        draw();
    }
}
