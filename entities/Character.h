#pragma once
#include "Entity.h"

namespace entes
{
    namespace Characters
    {
        class Character : public Entity
        {
            protected:

                int lives;
                bool alive;

            public:
                Character(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
                virtual ~Character();
        };
    }
}