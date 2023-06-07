#pragma once 
#include "Enemy.h"

#define TIME 200

namespace Entes
{
    namespace Characters
    {
        class Enemy1: public Enemy
        {
        private:
            int motion_counter;
        public:
            Enemy1(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
            ~Enemy1();
            void collide(Entity* other, std::string direction = "");
            void move();
            void save(std::ofstream& file);
        };   
    } 
}

