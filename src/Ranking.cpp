#include "../menus/Ranking.h"


namespace Menus
{
    Ranking::Ranking(std::string ranking):
    Menu(2, 4, "Ranking"),
    first("1 name - points"),
    second("2 name - points"),
    third("3 name - points"),
    ranking_file(ranking),
    rank()
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
        save();
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

    void Ranking::draw()
    {
        //printf ("\nDraw Ranking");

        pGM->draw(&(this->body));

        title.draw();

 
        first.draw();

        second.draw();

        third.draw();

        for (int i = 0; i < 2; i++)
        {
            buttons[i]->draw();
        }


    } 
    void Ranking::add_newRanking(int points, std::string name)
    {
        rank.insert(std::make_pair(points, name));
        
        std::map<int, std::string>::iterator it = rank.begin();
        for (int i = 0; i < 3 && it != rank.end(); i++, it++)
        {
            if (i == 0)
                first.setName(it->second + " - " + std::to_string(it->first));
            else if (i == 1)
                second.setName(it->second + " - " + std::to_string(it->first));
            else
                third.setName(it->second + " - " + std::to_string(it->first));
        }

    }
    void Ranking::save()
    {
        std::ofstream file(RANKING);
        if (!file)
        {
            std::cout<<"Cannot open ranking file"<<std::endl;
            exit(1);
        }     
        
        std::map<int, std::string>::iterator it = rank.begin();
        for (int i = 0; i < 3; i++, it++)
        {
            file << it->second << std::endl << it->first <<std::endl << std::endl;
        }
        file.close(); 
    }
    void Ranking :: load ()
    {
        std::ifstream file(RANKING);
        if (!file)
        {
            std::cout<<"Cannot open ranking file"<<std::endl;
            exit(1);
        }     
        int points;
        std::string name;
        for (int i = 0; i < 3; i++)
        {
            file>>name>>points;
            rank.insert(std::make_pair(points, name));
        }
        file.close(); 

        std::map<int, std::string>::iterator it = rank.begin();
        for (int i = 0; i < 3 && it != rank.end(); i++, it++)
        {
            if (i == 0)
                first.setName(it->second + " - " + std::to_string(it->first));
            else if (i == 1)
                second.setName(it->second + " - " + std::to_string(it->first));
            else
                third.setName(it->second + " - " + std::to_string(it->first));
        }
    }
}