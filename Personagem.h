#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"


class Personagem : public Entity
{
    protected:
        bool alive;
        int lives;
        sf::Vector2f vel;
        static int n_inimigos;
    public:
        Personagem();
         ~ Personagem();
        virtual void move() = 0;
};
