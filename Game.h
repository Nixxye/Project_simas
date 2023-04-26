#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

#define WIDTH 1000
#define HEIGHT 1000

class Game
{
private:
    sf::RenderWindow window;
    Player player;
    Enemy enemy;
public:
    Game();
    ~Game();
    void run();
};