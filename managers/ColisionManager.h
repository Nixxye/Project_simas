#pragma once

#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include "../entities/Obstacle.h"
#include "../lists/EntityList.h"

using namespace list;

namespace Managers
{
    class ColisionManager
    {
    private:
        EntityList enemy_list;
        EntityList player_list;
        EntityList obstacle_list;
    public:
        ColisionManager();
        ~ColisionManager();
        
        void add_enemy(Entity* ent){enemy_list.add(ent);}
        void add_player(Entity* ent){player_list.add(ent);}
        void add_obstacle(Entity* ent){obstacle_list.add(ent);}

        void colide();
        void check_colision(Entity* A, Entity* B);

    };
}