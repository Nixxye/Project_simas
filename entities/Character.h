#pragma once
#include "Entity.h"

namespace Entes
{
    namespace Characters
    {
        class Character : public Entity
        {
            protected:

                int lives;
                bool alive;
            public:
                Character(int index = -1, sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
                virtual ~Character();
                virtual void run() = 0;
                virtual void collide(Entity* other) = 0;
        };
    }
}