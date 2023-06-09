#pragma once

#define WIDTH 800
#define HEIGHT 600

#include <SFML/Graphics.hpp>

#include "../entities/Hud.h"
#include "../entities/Entity.h"
#include "../entities/Player.h"
#include "../entities/Enemy1.h"
#include "../entities/Enemy2.h"
#include "../entities/Boss.h"
#include "../entities/Platform.h"
#include "../entities/Slime.h"
#include "../entities/Spike.h"
#include "../lists/EntityList.h"
#include "../managers/ColisionManager.h"
#include "../managers/GraphicsManager.h"
#include "../managers/EventsManager.h"
#include "../managers/StateManager.h"
#include "../states/State.h"
#include "../stages/Stage.h"
#include "../managers/StateManager.h"

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

        Lists::EntityList obstacles;
        Lists::EntityList enemies;
        Lists::EntityList players;
        Lists::EntityList bullets;

        std::string save_file;
        std::string stage_info;
        std::string save_base;

        Entes::Hud hud;
        
        Managers::ColisionManager colision_manager;
        Managers::EventsManager* events_manager;

        bool loaded;
        
        sf::RectangleShape body;
    public:
        Stage(std::string savefile = "", std::string infofile = "", std::string savebase = "", int id = -1);
        virtual ~Stage();
        void virtual execute() = 0;
        void draw();

        void add_enemy(Entes::Entity* enemy);
        void add_obstacle(Entes::Entity* obstacle);
        void add_player(Entes::Entity* player);
        void add_bullet(Entes::Entity* bullet);

        virtual void save() = 0;
        virtual void load() = 0;
        virtual void reset() = 0;

        Entes::Entity* create_enemy(std::ifstream& file);
        //Provavelmente vai sair tbm:
        Entes::Entity* create_bullet(int id, sf::Vector2f pos, sf::Vector2f vel, float lifetime, Entes::Entity* boss);
        void create_scenario(std::string file);
        //void set_nplayers(int n);

    };
}
