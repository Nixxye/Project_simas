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

#include <fstream>
#include <string>
#include <iostream>

#define FILE_STAGE_1 "../savestate1.txt"

using namespace Managers;
using namespace entes;
using namespace list;
using namespace characters;
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
        string filename;
        ColisionManager colision_manager;
        sf::RenderWindow window;
    public:
        Stage();
        virtual ~Stage();
        virtual void run() = 0;
        virtual void create_enemies();
        virtual void create_obstacles();
        
        void add_enemy(Entity* enemy);
        void add_obstacle(Entity* obstacle);
        void add_player(Entity* player);

        void save();
        void load();
    };
}
