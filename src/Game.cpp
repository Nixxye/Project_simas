#include "../main/Game.h"

Game::Game():
graphics_manager(Managers::GraphicsManager::get_instance()),
stage1(),
main_menu()
{
    run();
}

Game::~Game()
{
}

void Game::run()
{
    while (graphics_manager->window_open())
    {
        graphics_manager->clean();
        //main_menu.run();
        //stage1.run();
        
        graphics_manager->show();
    }  
}
