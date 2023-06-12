#pragma once 
#include "Enemy.h"
#include "../lists/EntityList.h"

namespace Entes
{
    namespace Characters
    {
        class Bomb: public Enemy
        {
        private:
            float sensor_radius;
            Lists::EntityList* players;
            bool attacking;
            sf::Vector2f axis;
            float burst;
            sf::CircleShape explosion;
            float power;
            bool exploding;
        public:
            Bomb(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f), Lists::EntityList* p = nullptr);
            Bomb(bool alv, int lf, sf::Vector2f pos, sf::Vector2f velocity, float dmg, sf::Vector2f size, Lists::EntityList* p, float sr, bool atck, sf::Vector2f axs, float brst, float pw);
            ~Bomb();
            void collide(Entity* other, std::string direction = "");
            void move();
            void attack(sf::Vector2f target);
            void explode();
            void set_power(int pw) { power = pw; }
            void save(std::ofstream& file);
            void draw();
        };    
    }
}

