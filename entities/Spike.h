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
                Spike(sf::Vector2f pos, int dmg = 1);
                ~Spike();
                void collide(Entity* other, std::string  direction = "");
                void execute();
                void move();
                const int get_damage() const { return damage; }
        };    
    }    
}

