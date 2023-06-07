#pragma once

#include "Character.h"
#include "../entities/Player.h"

#include <SFML/Graphics.hpp>

namespace Entes
{
    namespace Characters
    {
        class Enemy: public Character
        {
        protected:
            int damage;
        public:
            Enemy(int index = -1, sf::Vector2f pos = sf::Vector2f(10.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
            virtual ~Enemy();
            void execute();
            virtual void move();
            virtual void collide(Entity* other, std::string  direction = "") = 0;
            const int get_damage() const { return damage; }
            virtual void save(std::ofstream& file) = 0;
        };
    }    
}

