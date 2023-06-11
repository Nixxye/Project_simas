#pragma once

#include "../entities/Ent.h"
#include "../lists/EntityList.h"
#include "../entities/Character.h"
#include "../menus/Text.h"

#include <vector>
//Hud com threads:

namespace Entes
{
    class Hud: public Ent
    {
    private:
        static int points;
        Lists::EntityList* players;
        std::vector<int> life;
        std::vector<sf::Vector2f> position;

        int kills;
        static bool win;
        bool isPaused;
        float clock;
        Menus::Text time;
        std::vector<sf::RectangleShape> life_bars;

        void draw_bars();
        void update_life();
    public:
        Hud(Lists::EntityList* p = nullptr);
        ~Hud();
        static const int get_points() { return points; }
        static void add_points(int pts) { points += pts; }

        void draw();

        void execute();
        static const bool get_win() { return win; }
        static void set_win(bool w) { win = w; }
    };
}