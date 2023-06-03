#include "../menus/GameOver.h"


namespace Menus
{
    GameOver::GameOver():
    Menu(1, 3),
    title("Game Over")
    {   
        title.setSize(60);
        title.setPosition(sf::Vector2f(60.f, 80.f));
        name_string = "Name:";
        pGOObserver = new Observers::GameOverObserver;
        pGOObserver->set_menu(this);
    }
    GameOver::~GameOver()
    {
        save();
    }

    void GameOver::draw()
    {
        title.draw();
        name.draw();
    } 
    void GameOver::add_name(std::string c)
    {
        name_string.append(c);
        printf ("Oi\n");
    } 

    void GameOver::set_name(std::string s)
    {
        name.setName(s);
        name.setPosition(sf::Vector2f(60.f, 200.f));
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