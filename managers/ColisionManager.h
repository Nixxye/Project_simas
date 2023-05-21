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
        EntityList* enemy_list;
        EntityList* player_list;
        EntityList* obstacle_list;
    public:
        ColisionManager();
        ~ColisionManager();
        
        void set_enemy_list(EntityList* list){ if (list) { enemy_list = list; }}
        void set_player_list(EntityList* list){ if (list) { player_list = list; }}
        void set_obstacle_list(EntityList* list){ if (list) { obstacle_list = list; }}

        void colide();
        void check_colision(Entity* A, Entity* B);

    };
}