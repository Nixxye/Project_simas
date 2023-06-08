#pragma once

#include "../entities/Ent.h"
//Hud com threads:

namespace Entes
{
    class Hud: public Ent
    {
    private:
        int points;
        Hud();
        static Hud* instance;
    public:
        ~Hud();
        static const int get_points() { return 123; /*Points dps*/}
        static Hud* get_instance();
        void draw() {}
        void execute() {}
    };
}