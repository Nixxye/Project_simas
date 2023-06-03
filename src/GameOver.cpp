#include "../menus/GameOver.h"


namespace Menus
{
    GameOver::GameOver():
    Menu(2, 3),
    title("Game Over")
    {   
        title.setSize(60);
        title.setPosition(sf::Vector2f(60.f, 80.f));
        name_string = "Name:";
        pGOObserver = new Observers::GameOverObserver;
        pGOObserver->set_menu(this);
        set_points(123);
        buttons_active = false;

    }
    GameOver::~GameOver()
    {
        save();
    }

    void GameOver::draw()
    {
        title.draw();
        name.draw();
        if (buttons_active)
        {
            buttons_draw();
            printf ("\n\n\nOIIIIII");
        }
    } 
    void GameOver::add_name(std::string c)
    {
        name_string.append(c);
        printf ("Oi\n");
    } 

    void GameOver::set_final_name()
    {
        if (name_string == "Name:")
            return;
        name_string.append (" - points:");
        name_string.append (points_string);
    
        name.setName(name_string);
        name.setPosition(sf::Vector2f(60.f, 450.f));
        buttons_active = true;


    } 

    std::string GameOver :: get_name_string ()
    {
        return name_string;
    }

    void  GameOver :: set_points (int p)
    {
        points_string = std::to_string(p);
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

    void GameOver  :: move_horizontally (int i)
    {

    }

    void GameOver  :: select ()
    {
        
        if (buttons_active)
        {
            switch (selected_index)
            {
            case 0:
                    States::State::pSM->set_CurrentState(0);
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