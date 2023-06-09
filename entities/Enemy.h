#pragma once

#include "Character.h"
#include <SFML/Graphics.hpp>

namespace Entes
{
    namespace Characters
    {
        class Enemy: public Character
        {
        protected:
        public:
            Enemy(int index = -1, sf::Vector2f pos = sf::Vector2f(10.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
            virtual ~Enemy();
            void run();
            virtual void move();
            virtual void collide(Entity* other, std::string  direction = "") = 0;
        };
    }    
}

