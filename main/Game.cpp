#include "../main/Game.h"

Game::Game():
graphics_manager(GraphicsManager::get_instance()),
stage1()
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
        graphics_manager->close_window();

        graphics_manager->clean();


        stage1.run();
        
        graphics_manager->show();
    }  
}
