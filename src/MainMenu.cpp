#include "../menus/MainMenu.h"


namespace Menus
{
    MainMenu::MainMenu():
    Menu(4, 0, "TimeAdventure++"),
    current_stage(1),
    current_player(0),
    stage1("Stage 1"),
    stage2("Stage 2"),
    player1 ("1 Player"),
    player2 ("2 Players")
    {   
        title.setSize(50);
        title.setPosition(sf::Vector2f(50.f, 25.f));
        title.set_color(0);
        stage1.setPosition(sf::Vector2f(100.f, 80.f));
        stage2.setPosition(sf::Vector2f(100.f, 80.f));
        
        player1.setPosition(sf::Vector2f(100.f, 125.f));
        player2.setPosition(sf::Vector2f(100.f, 125.f));

        buttons[0]->set_name("Continue");
        buttons[1]->set_name("New Game");
        buttons[2]->set_name("Ranking");
        buttons[3]->set_name("Quit");

        pMenuObserver = new Observers::MenuObserver;
        pMenuObserver->set_menu(this);

    }
    MainMenu::~MainMenu()
    {
        if (pMenuObserver)
            delete pMenuObserver;
        
        pMenuObserver = nullptr;
    }
    void MainMenu::select()
    {
        switch (selected_index)
        {
        case 0:
            if (current_stage == 1)
            {
                if (current_player == 0)
                    pSM->set_CurrentState(1);
                else
                    pSM->set_CurrentState(6);

            }
            else
            {
                if (current_player == 0)
                    pSM->set_CurrentState(2);
                else
                    pSM->set_CurrentState(5);
            }
            break;
        case 1:
            if (current_stage == 1)
            {
                if (current_player == 0)
                    pSM->set_CurrentState(1);
                else
                    pSM->set_CurrentState(6);
            }
            else
            {
                if (current_player == 0)
                    pSM->set_CurrentState(2);
                else
                    pSM->set_CurrentState(5);
            }
            pSM->reset_current_state();
            break;
        case 2:
        {
            
            States::State::pSM->set_CurrentState(4);
        }
            break;
        case 3:
            pGM->close_window();
            break;
        }
    }

    void MainMenu::move_horizontally(int i)
    {
        if (i == 1)
        {
            if (current_stage == 1)
            {
                current_stage = 2;
                texture = pGM->load_textures("../assets/menu2.png");
                body.setTexture(texture);
            }
            else
            {
                current_stage = 1;
                texture = pGM->load_textures("../assets/menu1.png");
                body.setTexture(texture);
            }
        }
        else if (i == 2)
            current_player = !current_player;

    }
    void MainMenu::draw()
    {
        pGM->draw(&(this->body));
        title.draw();
        if (!current_player)
            player1.draw();
        else 
            player2.draw();
        if (current_stage == 1)
            stage1.draw();
        else 
            stage2.draw();
        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            buttons[i]->draw();
        }
    } 
}