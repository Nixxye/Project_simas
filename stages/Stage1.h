#pragma once 

#include "../stages/Stage.h"

#define TIMETOFINISH 1000

#define ENEMY_FILE11 "../saves/stage1/enemies_1player.dat"
#define ENEMY_FILE12 "../saves/stage1/enemies_2players.dat"

#define PLAYER_RESET_FILE11 "../saves/stage1/reset_players1.dat"
#define PLAYER_RESET_FILE12 "../saves/stage1/reset_players2.dat"


#define ENEMY_RESET_FILE11 "../saves/stage1/reset_enemies_1player.dat"
#define ENEMY_RESET_FILE12 "../saves/stage1/reset_enemies_2players.dat"


#define SCENARIO_FILE1 "../saves/stage1/scenario.dat"
#define SAVE_SCENARIO1 "../saves/stage1/seed.dat"

#define PLAYER_FILE11 "../saves/stage1/players1.dat"
#define PLAYER_FILE12 "../saves/stage1/players2.dat"

namespace Stages
{
    class Stage1: public Stage
    {
    private:
        int finish;
    public:
        Stage1(int n_players);
        Stage1();
        ~Stage1();
        
        void execute();
        void save();
        void load();
        void reset();
    };
}