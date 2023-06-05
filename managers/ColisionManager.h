#pragma once

#include <SFML/Graphics.hpp>
#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include "../entities/Boss.h"
#include "../entities/Obstacle.h"
#include "../lists/EntityList.h"

//Coeficiente de restituição 
#define CR 0.65
//AS COLISÕES IRÃO RETORNAR 1 CASO COLIDIU E 0 DO CONTRÁRIO;
namespace Managers
{
    class ColisionManager
    {
    private:
        Lists::EntityList* enemy_list;
        Lists::EntityList* player_list;
        Lists::EntityList* obstacle_list;
        Lists::EntityList* bullet_list;
    public:
        ColisionManager();
        ~ColisionManager();
        
        void set_enemy_list(Lists::EntityList* list){ if (list) { enemy_list = list; }}
        void set_player_list(Lists::EntityList* list){ if (list) { player_list = list; }}
        void set_obstacle_list(Lists::EntityList* list){ if (list) { obstacle_list = list; }}
        void set_bullet_list(Lists::EntityList* list){ if (list) { bullet_list = list; }}

        void colide();
        void collide_attack(Entes::Characters::Player* Attacker, std::string direction);
        void collide_bullets(Entes::Entity* Bullet);
        void check_colision(Entes::Entity* A, Entes::Entity* B);
        void elastic_colision(Entes::Entity* A, Entes::Entity* B);
        void attack_and_bullets(sf::Vector2f attack_size, sf::Vector2f attack_position, sf::Vector2f player_vel, Entes::Entity* B);

    };
}