#include "../menus/MainMenu.h"

namespace Menus
{
    MainMenu::MainMenu():
    Menu(3)
    {   
        buttons[0]->set_name("Start");
        buttons[1]->set_name("Ranking");
        buttons[2]->set_name("Quit");
    }
    MainMenu::~MainMenu()
    {

    }
    void MainMenu::select()
    {
        std::cout<<"SELECTED"<<std::endl;
    }
}