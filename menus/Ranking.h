#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../observers/RankingObserver.h"

#include "../menus/Menu.h"
#define RANKING "../saves/ranking.dat"

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
        Observers::RankingObserver*  pRObserver;
        bool buttons_active;
    public:
        Ranking(std::string ranking = "");
        ~Ranking();
        void select();
        void move_horizontally(int i);
        void draw();
        void load();
    };
}