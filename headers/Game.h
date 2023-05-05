#pragma once

#include <SFML/Graphics.hpp>

#include "../headers/Entity.h"
#include "../headers/List.h"
#include "../headers/Player.h"
#include "../headers/Enemy.h"
#include "../headers/Obstacle.h"
#include "../headers/EntityList.h"

#define WIDTH 1000
#define HEIGHT 1000

class Game
{
private:
    sf::RenderWindow window;
    Player player;
    Enemy enemy;
    Obstacle platform;
    EntityList list;
public:
    Game();
    ~Game();
    void run();
};