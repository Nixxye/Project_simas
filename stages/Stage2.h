#pragma once

#include "../stages/Stage.h"

#define PLAYER_FILE2 "../saves/stage1/players.dat"
#define ENEMY_FILE2 "../saves/stage2/enemies.dat"
#define PLAYER_RESET_FILE2 "../saves/stage2/reset_players.dat"
#define ENEMY_RESET_FILE2 "../saves/stage2/reset_enemies.dat"
#define SCENARIO_FILE2 "../saves/stage2/scenario.dat"

namespace Stages
{
    class Stage2: public Stage
    {
    public:
        Stage2();
        ~Stage2();
        void execute();
        void save();
        //CARREGAR NO INÍCIO DO JOGO APENAS AS PLATAFORMAS:
        //Colocar um bool reset para saber se é para continuar ou dar new game
        void load();
        void reset();
    };
}

