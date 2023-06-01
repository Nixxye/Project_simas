#include "../main/Game.h"

Game::Game():
graphics_manager(Managers::GraphicsManager::get_instance()),
state_manager(Managers::StateManager::get_instance()),
events_manager(Managers::EventsManager::get_instance()),
stage1(),
stage2(),
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
        
        events_manager->run();
        state_manager->run();
        //main_menu.run();
        //stage1.run();
        //std::cout<<"Eita2"<<std::endl;
        graphics_manager->show();
        //std::cout<<"Eita3"<<std::endl;
    }  
}
