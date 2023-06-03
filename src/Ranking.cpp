#include "../menus/Ranking.h"


namespace Menus
{
    Ranking::Ranking(std::string ranking):
    Menu(1, 4),
    title("Ranking"),
    first("1 name - points"),
    second("2 name - points"),
    third("3 name - points"),
    ranking_file(ranking)
    {   
        load();
    }
    Ranking::~Ranking()
    {

    }
    void Ranking::select()
    {

    }

    void Ranking::move_horizontally(int i)
    {

    }
    void Ranking::draw()
    {
        
        pGM->reset_camera();

        title.setSize(70);
        title.setPosition(sf::Vector2f(WIDTH / 6, (2) *( SIZEY)));
        title.draw();

        first.setPosition(sf::Vector2f(WIDTH / 6, (3) *(SIZEY)));
        first.draw();

        second.setPosition(sf::Vector2f(WIDTH / 6, (4) *(SIZEY)));
        second.draw();

        third.setPosition(sf::Vector2f(WIDTH / 6, (5) *( SIZEY)));
        third.draw();


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