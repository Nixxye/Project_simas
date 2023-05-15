#pragma once

#include "../entities/GameObject.h"
#include "../lists/EntityList.h"
#include <fstream>
#include <string>
#include <iostream>

#define FILE_STAGE_1

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
    public:
        Stage();
        virtual ~Stage();
        virtual void run() = 0;
        virtual void create_enemies();
        virtual void create_obstacles();

        void save();
        void load();
    };
}
