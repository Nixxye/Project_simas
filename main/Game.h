#pragma once

#include <SFML/Graphics.hpp>

#include "../stages/Stage1.h"
#include "../stages/Stage2.h"
#include "../managers/GraphicsManager.h"
#include "../menus/MainMenu.h"
#include "../menus/GameOver.h"
#include "../menus/Ranking.h"
#include "../managers/StateManager.h"
#include "../managers/EventsManager.h"

class Game
{
private:
    Managers::GraphicsManager*  pGM;
    Managers::StateManager* pSM;
    Managers::EventsManager* pEM;
    Stages::Stage1 stage1;
    Stages::Stage1 stage1_2p;    
    Stages::Stage2 stage2;
    Stages::Stage2 stage2_2p;    
    Menus::MainMenu main_menu;
    Menus :: GameOver game_over;
    Menus :: Ranking ranking;

public:
    Game();
    ~Game();
    void execute();
};