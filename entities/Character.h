#pragma once
#include "Entity.h"

using namespace entes;
namespace characters
{
    class Character : public Entity
    {
        protected:
        public:
            Character(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
            virtual ~Character();
    };
}