#include "../menus/GameOver.h"


namespace Menus
{
    GameOver::GameOver():
    Menu(2, 3,"GameOver")
    {   
        title.setSize(65);
        title.setPosition(sf::Vector2f(120.f, 80.f));
        title.set_color(0);
        name_string = "Name:";
        pGOObserver = new Observers::GameOverObserver;
        pGOObserver->set_menu(this);
        set_points(123);
        buttons_active = false;
        final_name = false;
        name_active = false;

    }
    GameOver::~GameOver()
    {
        save();
    }

    void GameOver::draw()
    {
        title.draw();
        name.draw();
        if (buttons_active && final_name)
        {
            buttons_draw();
            printf ("\n\n\nOIIIIII");
        }
    } 
    void GameOver::add_name(std::string c)
    {
        if (name_active)
        {
            name_string.append(c);
            printf ("Oi\n");
        }
    } 

    void GameOver::set_final_name()
    {
        if (final_name)
            return;
        if (name_string == "Name:")
            return;
        name_string.append (" - points:");
        name_string.append (points_string);
    
        name.setName(name_string);
        name.setPosition(sf::Vector2f(60.f, 450.f));
        buttons_active = false;
        final_name = true;


    } 

    std::string GameOver :: get_name_string ()
    {
        return name_string;
    }

    void  GameOver :: set_points (int p)
    {
        points_string = std::to_string(p);
    }

    void GameOver :: active_name ()
    {
        if (!name_active)
        {
            name_active = true;
        }
    }
    void GameOver::draw_name()
    {
        name.draw();

    } 

    void GameOver :: buttons_draw ()
    {
        buttons[0]->set_name("Menu");
        buttons[1]->set_name("Quit");
        for (int i = 0; i < 2; i++)
        {
            buttons[i]->draw();
        }
    }


    void GameOver  :: select ()
    {
        if (!buttons_active)
        {
            buttons_active = true;
            return;
        }
        
        if (buttons_active)
        {
            switch (selected_index)
            {
            case 0:
            {
                buttons_active = false;
                States::State::pSM->set_CurrentState(0);

            }
                break;
            case 1:
                pGM->close_window();
                break;
            }
        }
    }

    void GameOver :: save ()
    {
         
    }
}