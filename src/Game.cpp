#include "../main/Game.h"

Game::Game():
pGM(Managers::GraphicsManager::get_instance()),
pSM(Managers::StateManager::get_instance()),
pEM(Managers::EventsManager::get_instance()),
stage1(),
main_menu(),
game_over(),
ranking()
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
        
        pEM->execute();
        pSM->get_CurrentState()->execute();
        //main_menu.run();
        //stage1.run();
        
        pGM->show();
    }  
}
