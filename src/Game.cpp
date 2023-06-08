#include "../main/Game.h"

Game::Game():
pGM(Managers::GraphicsManager::get_instance()),
pSM(Managers::StateManager::get_instance()),
pEM(Managers::EventsManager::get_instance()),
stage1(),
stage2(),
stage1_2p(2),
stage2_2p(2),
main_menu(),
ranking(),
game_over(&ranking)
{
    execute();
}

Game::~Game()
{
}

void Game::execute()
{
    while (pGM->window_open())
    {
        pGM->clean();
        
        pEM->run();
        pSM->run();
        //main_menu.run();
        //stage1.run();
        
        pGM->show();
    }  
}
