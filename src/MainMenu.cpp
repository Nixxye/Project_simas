#include "../menus/MainMenu.h"

namespace Menus
{
    MainMenu::MainMenu():
    Menu(4, 0),
    current_stage(1),
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
            if (current_stage == 1)
                pSM->set_CurrentState(1);
            else
                pSM->set_CurrentState(2);
            break;
        case 1:
            if (current_stage == 1)
            {
                pSM->set_CurrentState(1);
            }
            else
            {
                pSM->set_CurrentState(2);
            }
            pSM->reset_current_state();
            break;
        case 3:
            pGM->close_window();
            break;
        }
    }

    void MainMenu::move_horizontally()
    {
        if (current_stage == 1)
            current_stage = 2;
        else
            current_stage = 1;
    }
    void MainMenu::draw()
    {
        if (current_stage == 1)
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