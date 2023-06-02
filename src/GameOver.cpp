#include "../menus/GameOver.h"

namespace Menus
{
    GameOver::GameOver():
    Menu(1, 3),
    name()
    {   
        buttons[0]->set_name("Quit");
    }
    GameOver::~GameOver()
    {

    }
    void GameOver::select()
    {
        switch (selected_index)
        {
            case 0:
                pGM->close_window();
            break;
        }
    }

    void GameOver::draw()
    {

        buttons[0]->draw();

    } 
    void GameOver::set_name(char c)
    {
        std::string string;
        string += c;
        name.setName(string);

    } 
}