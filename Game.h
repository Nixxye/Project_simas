#pragma once

#include <SFML/Graphics.hpp>

#include "Entity.h"
#include "EntityList.h"
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
    EntityList list;
public:
    Game();
    ~Game();
    void run();
};