#include "../menus/Menu.h"

namespace Menus
{
    Menu :: Menu(int n_buttons, int id, std:: string t):
    Ent(),
    State(id),
    MAX_BUTTONS(n_buttons),
    buttons(),
    selected_index(0),
    title(t)
    {
        //pEventsManager = Managers::EventsManager::get_instance();
        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            buttons.push_back(new Button(sf::Vector2f(WIDTH / 2, (i + 2) *(20 + SIZEY))));
        }
        buttons[0]->change_color();

        body.setSize(sf::Vector2f(800.f, 600.f));
        texture = pGM->load_textures("../assets/menu1.png");
        body.setTexture(texture);


    }
    Menu :: ~Menu()
    {


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
    void Menu :: execute()
    {
        //pEventsManager->execute(); //nao entendi pq??
        draw();
    }
}
