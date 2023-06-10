#pragma once

#include "../entities/Ent.h"
#include "../lists/EntityList.h"
#include <vector>
//Hud com threads:

namespace Entes
{
    class Hud: public Ent
    {
    private:
        static int points;
        std::vector<int> life;
        //Tempo de jogo;
        int kills;
        static bool win;
    public:
        Hud();
        ~Hud();
        static const int get_points() { return points; }
        static void add_points(int pts) { points += pts; }
        //função para mudar a vida;
        void draw() {}
        void execute() {}
        static const bool get_win() { return win; }
        static void set_win(bool w) { win = w; }
    };
}