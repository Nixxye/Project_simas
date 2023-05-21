#pragma once

#include <SFML/Graphics.hpp>
#include "../stages/Stage1.h"
#include "../managers/GraphicsManager.h"

using namespace Managers;
using namespace Stages;

class Game
{
private:
    GraphicsManager* graphics_manager;
    Stage1 stage1;    
public:
    Game();
    ~Game();
    void run();
};