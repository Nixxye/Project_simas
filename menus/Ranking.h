#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../menus/Menu.h"
#define RANKING "../saves/arquivojkdjk"

namespace Menus
{
    class Ranking: public Menu
    {
    private:
        Text title;
        Text first;
        Text second;
        Text third;
        std::string ranking_file;
    public:
        Ranking(std::string ranking = "");
        ~Ranking();
        void select();
        void move_horizontally(int i);
        void draw();
        void load();
    };
}