#pragma once 

#include "../stages/Stage.h"

//#define PLAYER_FILE1 "../saves/stage1/players.dat"
#define ENEMY_FILE1 "../saves/stage1/enemies.dat"
#define PLAYER_RESET_FILE1 "../saves/stage1/reset_players.dat"
#define ENEMY_RESET_FILE1 "../saves/stage1/reset_enemies.dat"
#define SCENARIO_FILE1 "../saves/stage1/scenario.dat"
#define PLAYER_FILE11 "../saves/stage1/players1.dat"
#define PLAYER_FILE12 "../saves/stage1/players2.dat"

namespace Stages
{
    class Stage1: public Stage
    {
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