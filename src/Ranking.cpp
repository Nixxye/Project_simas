#include "../menus/Ranking.h"


namespace Menus
{
    Ranking::Ranking(std::string ranking):
    Menu(2, 4, "Ranking"),
    first("1 name - points"),
    second("2 name - points"),
    third("3 name - points"),
    ranking_file(ranking)
    {   

        title.setSize(70);
        title.setPosition(sf::Vector2f(160.f, 80.f));
        title.set_color(0);

        first.setPosition(sf::Vector2f(110.f, 160.f));
        second.setPosition(sf::Vector2f(110.f, 240.f));
        third.setPosition(sf::Vector2f(110.f, 320.f));
        
        load();
        buttons[0]->set_name("Menu");
        buttons[0]->set_position(sf::Vector2f(400.f, 420.f));

        buttons[1]->set_name("Quit");
        buttons[1]->set_position(sf::Vector2f(400.f, 520.f));


        buttons_active = false;
        pRObserver = new Observers::RankingObserver();
        pRObserver->set_menu(this);
    }
    Ranking::~Ranking()
    {
        if (pRObserver)
            delete pRObserver;
        
        pRObserver = nullptr;
    }
    void Ranking::select()
    {
        if (!buttons_active)
        {
            buttons_active = true;
            return;
        }
        
        if (buttons_active)
        {
            switch (selected_index)
            {
            case 0:
            {
                States::State::pSM->set_CurrentState(0);
                buttons_active = false;
            }
                break;
            case 1:
                pGM->close_window();
                break;
            }
        }
    }

    void Ranking::move_horizontally(int i)
    {

    }
    void Ranking::draw()
    {
        //printf ("\nDraw Ranking");



        title.draw();

 
        first.draw();

        second.draw();

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