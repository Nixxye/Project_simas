#pragma once
#include "Entity.h"

namespace entes

{
    namespace character
    {
        class Character : public Entity
        {
            protected:
            public:
                Character(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
                ~Character();
        };
    }
}