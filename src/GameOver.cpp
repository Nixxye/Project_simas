#include "../menus/GameOver.h"


namespace Menus
{
    GameOver::GameOver():
    Menu(1, 3),
    title("Game Over")
    {   
        name_string = "Name:";
    }
    GameOver::~GameOver()
    {
        save();
    }

    void GameOver::draw()
    {
        pGM->reset_camera();
        title.draw();
    } 
    void GameOver::add_name(std::string c)
    {
        name_string.append(c);
    } 

    void GameOver::set_name(std::string s)
    {
        name.setName(s);
        name.setPosition(sf::Vector2f(WIDTH / 2, (5)*(20 + SIZEY)));
    } 

    std::string GameOver :: get_name_string ()
    {
        return name_string;
    }


    void GameOver::draw_name()
    {
        name.draw();
    } 

    void GameOver  :: move_horizontally (int i)
    {

    }

    void GameOver  :: select ()
    {
        
    }

    void GameOver :: save ()
    {

    }
}