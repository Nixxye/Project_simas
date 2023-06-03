#include "../menus/Ranking.h"


namespace Menus
{
    Ranking::Ranking(std::string ranking):
    Menu(1, 4),
    title("Ranking"),
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

    void Ranking::move_horizontally()
    {

    }
    void Ranking::draw()
    {
        title.draw();
        first.draw();
        second.draw();
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