#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../menus/Menu.h"

namespace Menus
{
    class MainMenu: public Menu
    {
    private:
        int current_stage;
        int current_player;
        Text stage1;
        Text stage2;
        Text player1;
        Text player2;
    public:
        MainMenu();
        ~MainMenu();
        void select();
        void move_horizontally(int i);
        void draw();
    };
}