#pragma once

#include <SFML/Graphics.hpp>

#include "../entities/Entity.h"
#include "../entities/Player.h"
#include "../entities/Enemy.h"
#include "../entities/Boss.h"
#include "../entities/Obstacle.h"
#include "../lists/EntityList.h"
#include "../managers/ColisionManager.h"

using namespace Managers;
using namespace entes;
using namespace list;
using namespace characters;
using namespace obstacles;

#define WIDTH 800
#define HEIGHT 600

class Game
{
private:
    sf::RenderWindow window;
    Player player;
    Boss enemy;
    Obstacle platform, platform1, platform2;
    EntityList list;
    ColisionManager colision_manager;
public:
    Game();
    ~Game();
    void run();
};