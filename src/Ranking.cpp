#include "../menus/Ranking.h"


namespace Menus
{
    Ranking::Ranking(std::string ranking):
    Menu(2, 4),
    title("Ranking"),
    first("1 name - points"),
    second("2 name - points"),
    third("3 name - points"),
    ranking_file(ranking)
    {   
        load();
        buttons[0]->set_name("Menu");
        buttons[0]->set_position(sf::Vector2f(400.f, 420.f));

        buttons[1]->set_name("Quit");
        buttons[1]->set_position(sf::Vector2f(400.f, 520.f));
    }
    Ranking::~Ranking()
    {

    }
    void Ranking::select()
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

    void Ranking::move_horizontally(int i)
    {

    }
    void Ranking::draw()
    {
        
        pGM->reset_camera();

        title.setSize(70);
        title.setPosition(sf::Vector2f(50.f, 80.f));
        title.draw();

        first.setPosition(sf::Vector2f(50.f, 160.f));
        first.draw();

        second.setPosition(sf::Vector2f(50.f, 240.f));
        second.draw();

        third.setPosition(sf::Vector2f(50.f, 320.f));
        third.draw();

        for (int i = 0; i < 2; i++)
        {
            buttons[i]->draw();
        }


    } 
    void Ranking :: load ()
    {
        /*std::ifstream file ();
        std::string line;

        if (!file)
        {
            std::cout <<"ERROR: 454"<<std::endl;
            exit(2);
        }

        std::getline(file, line);

        if (line != "#first")
        {
            std::cout << "ERROR 6465 "<< std::endl;
            file.close();
            exit(3);
        }

        std::getline(file, line);
        std::getline(file, line);

        if (line != "#second")
        {
            std::cout << "ERROR 64115 "<< std::endl;
            file.close();
            exit(3);
        }
        std::getline(file, line);
        std::getline(file, line);

        if (line != "#third")
        {
            std::cout << "ERROR 6444515 "<< std::endl;
            file.close();
            exit(3);
        }


 

        file.close();*/

    }
}