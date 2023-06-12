#pragma once

#include <SFML/Graphics.hpp>
#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include "../entities/Boss.h"
#include "../entities/Obstacle.h"
#include "../lists/EntityList.h"

//Coeficiente de restituição 
#define CR 0.30

namespace Managers
{
    class ColisionManager
    {
    private:
        Lists::EntityList* enemy_list;
        Lists::EntityList* player_list;
        Lists::EntityList* obstacle_list;
                
        void check_colision(Entes::Entity* A, Entes::Entity* B);
    public:
        ColisionManager();
        ~ColisionManager();
        
        void set_enemy_list(Lists::EntityList* list){ if (list) { enemy_list = list; }}
        void set_player_list(Lists::EntityList* list){ if (list) { player_list = list; }}
        void set_obstacle_list(Lists::EntityList* list){ if (list) { obstacle_list = list; }}

        void colide();
        void collide_attack(Entes::Characters::Player* Attacker, std::string direction);
        void collide_bullets(Entes::Entity* Bullet);

        void elastic_colision(Entes::Entity* A, Entes::Entity* B);
        void elastic_colision(sf::CircleShape* A, Entes::Entity* B, float cr);
        void attack_and_bullets(sf::Vector2f attack_size, sf::Vector2f attack_position, Entes::Entity* player, Entes::Entity* B, sf::Vector2f vel);
        
        void collide_explosion(sf::CircleShape* explosion, float power);
    };
}