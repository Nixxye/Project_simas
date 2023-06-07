#pragma once

#include "../stages/Stage.h"
#define PLAYER_FILE2 "../saves/stage2/players.dat"
#define ENEMY_FILE2 "../saves/stage2/enemies.dat"

namespace Stages
{
    class Stage2: public Stage
    {
    public:
        Stage2();
        ~Stage2();
        void execute();
        void save();
        //Colocar um bool reset para saber se é para continuar ou dar new game
        void load();
    };
}

