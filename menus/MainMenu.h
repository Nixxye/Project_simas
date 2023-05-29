#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../menus/Menu.h"

namespace Menus
{
    class MainMenu: public Menu
    {
    private:

    public:
        MainMenu();
        ~MainMenu();
        void select();
    };
}