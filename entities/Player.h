#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

#include "../entities/Character.h"
#include "../observers/PlayerObserver.h"

#define ATTACK_DELAY 30
//Implementar se tiver tempo, um recoil;
#define RECOIL 5
#define DMG 3

namespace Entes
{
    namespace Characters
    {
        class Player : public Character
        {
        private:
            Observers::PlayerObserver *pPObserver;
            sf::RectangleShape attack_body;
            bool is_attacking;
            int attack_delay;
            
        public:
            Player(int index = 1,sf::Vector2f pos = sf::Vector2f(10.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
            ~Player();
            void run();
            void move(char direction = '0');
            void collide(Entity *other, std::string  direction = "");
            void attack();

            //void set_colision_manager(Managers::ColisionManager* cm) { colision_manager = cm; }

            sf::Vector2f get_attack_position() { return attack_body.getPosition(); }
            sf::Vector2f get_attack_size() { return attack_body.getSize(); }
            Observers::Observer* get_observer() { return pPObserver; }
        };
    }
}
