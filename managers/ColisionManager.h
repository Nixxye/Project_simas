#pragma once

#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include "../entities/Obstacle.h"
#include "../lists/EntityList.h"

namespace Managers
{
    class ColisionManager
    {
    //considerando que o player é o primeiro elemento da lista;
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
        void aux_col(Entity* A, Entity* B);

    };
}