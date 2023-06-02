#pragma once

#define WIDTH 800
#define HEIGHT 600

#include <SFML/Graphics.hpp>

#include "../entities/Entity.h"
#include "../entities/Player.h"
#include "../entities/Enemy1.h"
#include "../entities/Enemy2.h"
#include "../entities/Enemy3.h"
#include "../entities/Boss.h"
#include "../entities/Obstacle.h"
#include "../lists/EntityList.h"
#include "../managers/ColisionManager.h"
#include "../managers/GraphicsManager.h"
#include "../managers/EventsManager.h"
#include "../managers/StateManager.h"
#include "../states/State.h"
#include "../observers/StageObserver.h"
#include "../stages/Stage.h"

#include <fstream>
#include <string>
#include <iostream>

//Windows:
/*
#define SAVE_STAGE_1 "saves/savestate1.dat"
#define FILE_STAGE_1 "saves/stage1.dat"
#define SAVE_BASE_1 "saves/savebase1.dat"

#define SAVE_STAGE_2 "saves/savestate2.dat"
#define FILE_STAGE_2 "saves/stage2.dat"
#define SAVE_BASE_2 "saves/savebase2.dat"
*/
//Linux:

#define FILE_STAGE_1 "../saves/stage1.dat"
#define SAVE_STAGE_1 "../saves/savestate1.dat"
#define SAVE_BASE_1 "../saves/savebase1.dat"

#define SAVE_STAGE_2 "../saves/savestate2.dat"
#define FILE_STAGE_2 "../saves/stage2.dat"
#define SAVE_BASE_2 "../saves/savebase2.dat"

namespace Stages
{
    class Stage: public Ent, public States::State
    {
    protected:
        Observers::StageObserver* pSObserver;

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
        void draw();

        virtual void run () = 0;

        void add_enemy(Entes::Entity* enemy);
        void add_obstacle(Entes::Entity* obstacle);
        void add_player(Entes::Entity* player);

        void save();
        void load();
        void reset();

        Entes::Entity* create_enemy(int id, sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f size);

        void setObservers();
    };
}
