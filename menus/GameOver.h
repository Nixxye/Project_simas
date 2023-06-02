#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../menus/Menu.h"
#include "../observers/GameOverObserver.h"


namespace Menus 
{

    class GameOver : public Menu 
    {
    private:
        Text title;
        Text points;
        Text name;

    public:
        GameOver();

        ~GameOver();

        void draw();

        void select ();

        void set_name (char c);

    };

}