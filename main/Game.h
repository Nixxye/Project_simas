#pragma once

#include <SFML/Graphics.hpp>

#include "../stages/Stage1.h"
#include "../stages/Stage2.h"
#include "../managers/GraphicsManager.h"
#include "../menus/MainMenu.h"
#include "../managers/StateManager.h"
#include "../managers/EventsManager.h"

class Game
{
private:
    Managers::GraphicsManager*  pGM;
    Managers::StateManager* pSM;
    Managers::EventsManager* pEM;
    Stages::Stage1 stage1;  
    Stages::Stage2 stage2;  
    Menus::MainMenu main_menu;
public:
    Game();
    ~Game();
    void run();
};