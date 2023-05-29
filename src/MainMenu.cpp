#include "../menus/MainMenu.h"

namespace Menus
{
    MainMenu::MainMenu():
    Menu(3)
    {   
        buttons[0]->setString("Start");
        buttons[1]->setString("Ranking");
        buttons[2]->setString("Quit");
    }
    MainMenu::~MainMenu()
    {

    }
    void MainMenu::select()
    {
        std::cout<<"SELECTED"<<std::endl;
    }
}