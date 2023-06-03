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
        Text title;
        std::string name_string ;
        Text name;

    public:
        GameOver();

        ~GameOver();

        void draw();

        void add_name(std::string c);

        void set_name (std::string s);

        std::string get_name_string ();

        void draw_name ();

        void move_horizontally(int i );

        void select ();

        void save ();

    };

}