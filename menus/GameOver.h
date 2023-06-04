#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "../menus/Menu.h"
#include "../observers/GameOverObserver.h"


namespace Menus 
{

    class GameOver : public Menu 
    {
    private:
        std::string name_string ;
        std :: string points_string;
        Text name;
        Observers::GameOverObserver*  pGOObserver;
        bool buttons_active;
        bool name_active;
        bool final_name;



    public:
        GameOver();

        ~GameOver();

        void draw();

        void add_name(std::string c);

        void set_final_name ();

        void set_points (int p);

        std::string get_name_string ();

        void draw_name ();

        void active_name();
        
        void select ();

        void save ();

        void buttons_draw();

    };

}