#pragma once

#include <SFML/Graphics.hpp>
#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include "../entities/Obstacle.h"
#include "../lists/EntityList.h"

namespace Managers
{
    class ColisionManager
    {
    private:
        Lists::EntityList* enemy_list;
        Lists::EntityList* player_list;
        Lists::EntityList* obstacle_list;
    public:
        ColisionManager();
        ~ColisionManager();
        
        void set_enemy_list(Lists::EntityList* list){ if (list) { enemy_list = list; }}
        void set_player_list(Lists::EntityList* list){ if (list) { player_list = list; }}
        void set_obstacle_list(Lists::EntityList* list){ if (list) { obstacle_list = list; }}

        void colide();
        void check_colision(Entes::Entity* A, Entes::Entity* B);

    };
}