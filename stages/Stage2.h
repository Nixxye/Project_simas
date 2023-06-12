#pragma once

#include "../stages/Stage.h"

//#define PLAYER_FILE2 "../saves/stage2/players.dat"
#define ENEMY_FILE21 "../saves/stage2/enemies_1player.dat"
#define ENEMY_FILE22 "../saves/stage2/enemies_2players.dat"
#define PLAYER_RESET_FILE21 "../saves/stage2/reset_players1.dat"
#define PLAYER_RESET_FILE22 "../saves/stage2/reset_players2.dat"


#define ENEMY_RESET_FILE21 "../saves/stage2/reset_enemies_1player.dat"
#define ENEMY_RESET_FILE22 "../saves/stage2/reset_enemies_2players.dat"

#define SCENARIO_FILE2 "../saves/stage2/scenario.dat"
#define SAVE_SCENARIO2 "../saves/stage2/seed.dat"

#define PLAYER_FILE21 "../saves/stage2/players1.dat"
#define PLAYER_FILE22 "../saves/stage2/players2.dat"

namespace Stages
{
    class Stage2: public Stage
    {
    private:
        bool anyEnemyAlive;
    public:
        Stage2();
        Stage2(int n_players);
        ~Stage2();
        void execute();
        void save();
        void load();
        void reset();
    };
}

