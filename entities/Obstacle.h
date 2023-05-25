#pragma once
#include "Entity.h"

using namespace Entes;
namespace obstacles
{
    class Obstacle: public Entity
    {
        protected:
        public:
            Obstacle(sf::Vector2f pos = sf::Vector2f(100.f, 600.f), sf::Vector2f size = sf::Vector2f(1000.f, 100.f));
            ~Obstacle();
            void run();
            void collide(Entity* other){};
    };    
}
