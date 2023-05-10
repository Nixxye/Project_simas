#pragma once

#include <SFML/Graphics.hpp>

#include "../entities/Entity.h"
#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include "../entities/Obstacle.h"
#include "../lists/EntityList.h"
#include "../managers/ColisionManager.h"

using namespace Managers;
using namespace entes;
using namespace list;
#define WIDTH 800
#define HEIGHT 600

class Game
{
private:
    sf::RenderWindow window;
    Player player;
    Enemy enemy;
    Obstacle platform, platform1, platform2;
    EntityList list;
    ColisionManager colision_manager;
public:
    Game();
    ~Game();
    void run();
};