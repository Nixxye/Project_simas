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
            Enemy(sf::Vector2f pos = sf::Vector2f(10.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
            ~Enemy();
            void run();
            void move();
        };
    }    
}

