#pragma once 

#include "Obstacle.h"

namespace Entes
{
    namespace Obstacles
    {
        class Spike : public Obstacle
        {
            private:
                int damage;
            public:
                Spike(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
                ~Spike();
                void collide(Entity* other, std::string  direction = "");
                void execute(){}
                const int get_damage() const { return damage; }
        };    
    }    
}

