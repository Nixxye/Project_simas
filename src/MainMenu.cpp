#include "../menus/MainMenu.h"

namespace Menus
{
    MainMenu::MainMenu():
    Menu(4, 0),
    current_stage(0),
    stage1("Stage 1"),
    stage2("Stage 2")    
    {   
        buttons[0]->set_name("Continue");
        buttons[1]->set_name("New Game");
        buttons[2]->set_name("Ranking");
        buttons[3]->set_name("Quit");
    }
    MainMenu::~MainMenu()
    {

    }
    void MainMenu::select()
    {
        switch (selected_index)
        {
        case 0:
            if (!current_stage)
                States::State::pSM->set_CurrentState(1);
            break;
        case 1:
            if (!current_stage)
            {
                States::State::pSM->set_CurrentState(1);
                States::State::pSM->reset_current_state();
            }
            break;
        case 3:
            graphics_manager->close_window();
            break;
        }
    }

    void MainMenu::move_horizontally()
    {
        current_stage = !current_stage;
    }
    void MainMenu::draw()
    {
        if (!current_stage)
            stage1.draw();
        else 
            stage2.draw();
        for (int i = 0; i < MAX_BUTTONS; i++)
        {
            //arrumar a função de draw do graphics_manager
            buttons[i]->draw();
        }
    } 
}