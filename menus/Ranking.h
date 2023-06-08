#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "../observers/RankingObserver.h"

#include "../menus/Menu.h"
#define RANKING "../saves/ranking.dat"

namespace Menus
{
    class Ranking: public Menu
    {
    private:
        Text first;
        Text second;
        Text third;
        std::string ranking_file;
        Observers::RankingObserver*  pRObserver;
        bool buttons_active;
        std::multimap<int, std::string, std::greater<int>> rank;
    public:
        Ranking(std::string ranking = "");
        ~Ranking();
        void select();
        void draw();
        void load();
        void save();
        void add_newRanking(int points, std::string name);
    };
}