#pragma once

#define WIDTH 800
#define HEIGHT 600

#include <SFML/Graphics.hpp>

#include "../entities/Entity.h"
#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include "../entities/Boss.h"
#include "../entities/Obstacle.h"
#include "../lists/EntityList.h"
#include "../managers/ColisionManager.h"
#include "../managers/GraphicsManager.h"
#include "../managers/EventsManager.h"
#include "../states/State.h"

#include <fstream>
#include <string>
#include <iostream>

//Windows:

#define SAVE_STAGE_1 "saves/savestate1.dat"
#define FILE_STAGE_1 "saves/stage1.dat"

//Linux:
/*
#define FILE_STAGE_1 "../saves/stage1.dat"
#define SAVE_STAGE_1 "../saves/savestate1.dat"
*/

using namespace Managers;
using namespace Entes;
using namespace Lists;
using namespace Entes::Characters;
using namespace obstacles;
using namespace std;

namespace Stages
{
    class Stage: public GameObject
    {
    protected:
        EntityList obstacles;
        EntityList enemies;
        EntityList players;
        string save_file;
        string stage_info;
        ColisionManager colision_manager;
        EventsManager* events_manager;
    public:
        Stage(string savefile = "", string infofile = "");
        virtual ~Stage();
        virtual void run() = 0;
        virtual void create_enemies();
        virtual void create_obstacles();
        void draw();
        
        void add_enemy(Entity* enemy);
        void add_obstacle(Entity* obstacle);
        void add_player(Entity* player);

        void save();
        void load();
    };
}
