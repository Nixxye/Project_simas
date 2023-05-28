#pragma once

#include <SFML/Graphics.hpp>
#include "../stages/Stage1.h"
#include "../managers/GraphicsManager.h"
#include "../menus/MainMenu.h"

class Game
{
private:
    Managers::GraphicsManager* graphics_manager;
    Stages::Stage1 stage1;    
    Menus::Main_Menu main_menu;
public:
    Game();
    ~Game();
    void run();
};