#include "../main/Game.h"

Game::Game():
window(sf::VideoMode(WIDTH, HEIGHT), "Project Simas"),
player(),
enemy(),
platform(),
list()
//colision_manager()
{
    list.add(static_cast<Entity*>(&player));
    list.add(static_cast<Entity*>(&enemy));
    list.add(static_cast<Entity*>(&platform));

    colision_manager.add_player(&player);
    colision_manager.add_enemy(static_cast<Entity*>(&enemy));
    colision_manager.add_obstacle(static_cast<Entity*>(&platform));

    window.setFramerateLimit(60);
    run();
}

Game::~Game()
{
}

void Game::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        //player.move();
        //enemy.move();
        list.move();
        colision_manager.colide();
        //list.stress_test();
        //player.draw(&window);
        //enemy.draw(&window);
        platform.draw(&window);
        list.draw(&window);

        window.display();
    }
}
