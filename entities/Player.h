#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>
#include "../entities/Character.h"

namespace characters
{
    class Player: public Character
    {
    private:

    public:
        Player(sf::Vector2f pos = sf::Vector2f(10.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
        ~Player();
        void run();
        void move(char direction = ' ');
    };
}
