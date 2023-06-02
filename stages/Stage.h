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
#include "../observers/StageObserver.h"
#include "../stages/Stage.h"
#include "../managers/StateManager.h"

#include <fstream>
#include <string>
#include <iostream>

//Windows:
/*
#define SAVE_STAGE_1 "saves/savestate1.dat"
#define FILE_STAGE_1 "saves/stage1.dat"
#define SAVE_BASE_1 "saves/savebase1.dat"*/
//Linux:

#define FILE_STAGE_1 "../saves/stage1.dat"
#define SAVE_STAGE_1 "../saves/savestate1.dat"
#define SAVE_BASE_1 "../saves/savebase1.dat"

namespace Stages
{
    class Stage: public Ent, public States::State
    {
    protected:
        Observers::StageObserver* pSObserver;
        Managers::StateManager* pSM;

        Lists::EntityList obstacles;
        Lists::EntityList enemies;
        Lists::EntityList players;

        std::string save_file;
        std::string stage_info;
        std::string save_base;
        
        Managers::ColisionManager colision_manager;
        Managers::EventsManager* events_manager;
    public:
        Stage(std::string savefile = "", std::string infofile = "", std::string savebase = "", int id = -1);
        virtual ~Stage();
        virtual void run() = 0;
        virtual void create_enemies();
        virtual void create_obstacles();
        void draw();
        
        void add_enemy(Entes::Entity* enemy);
        void add_obstacle(Entes::Entity* obstacle);
        void add_player(Entes::Entity* player);

        void save();
        void load();
        void reset();

        void setObservers();
    };
}
