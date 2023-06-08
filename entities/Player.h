#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

#include "../entities/Character.h"


#define ATTACK_DELAY 30
//Implementar se tiver tempo, um recoil;
#define RECOIL 5
#define DMG 3
#define SLOW_TIME 100

namespace Entes
{
    namespace Characters
    {
        class Player : public Character
        {
        private:
            sf::RectangleShape attack_body;
            bool is_attacking;
            int attack_delay;
            int player_id;
            bool win;
            
            int damage;  
            //Salvar attack_delay          
        public:
            Player(int index = 1,sf::Vector2f pos = sf::Vector2f(10.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
            Player(int index, bool alv, int lf, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size);
            ~Player();

            void execute();
            void move(char direction = '0');
            void collide(Entity *other, std::string  direction = "");
            void collide_attack(Entity *other, std::string direction = "");
            void attack();
            void set_win (bool b){win = b;}
            bool get_win() {return win;}

            //void set_colision_manager(Managers::ColisionManager* cm) { colision_manager = cm; }

            sf::Vector2f get_attack_position() { return attack_body.getPosition(); }
            sf::Vector2f get_attack_size() { return attack_body.getSize(); }
            const int get_damage() const { return damage; }

            void draw();
            void save(std::ofstream& file);

            void set_slowed(int s);
        };
    }
}
