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
        Text stage1;
        Text stage2;
    public:
        MainMenu();
        ~MainMenu();
        void select();
        void move_horizontally();
        void draw();
    };
}