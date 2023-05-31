#pragma once 
#include "Enemy.h"

namespace Entes
{
    namespace Characters
    {
        class Enemy3: public Enemy
        {
        private:
        public:
            Enemy3(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
            ~Enemy3();
            void collide(Entity* other){};
        
        };    
    }
}

