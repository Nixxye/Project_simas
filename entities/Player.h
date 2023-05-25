#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>
#include <string>

#include "../entities/Character.h"
#include "../observers/PlayerObserver.h"

namespace Entes
{
    namespace Characters
    {
        class Player: public Character
        {
        private:
            Observers::PlayerObserver* pPObserver;
        public:
            Player(sf::Vector2f pos = sf::Vector2f(10.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
            ~Player();
            void run();
            //Arrumar esse negócio feio
            void move(char direction = '0');
        };
    }
}
