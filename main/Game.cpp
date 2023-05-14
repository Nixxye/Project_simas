#include "../main/Game.h"

Game::Game():
window(sf::VideoMode(WIDTH, HEIGHT), "Project Simas"),
player(),
enemy(),
platform(sf::Vector2f(100.f, 400.f), sf::Vector2f(500.f, 40.f)),
platform1(sf::Vector2f(400.f, 550.f), sf::Vector2f(500.f, 40.f)),
platform2(sf::Vector2f(700.f, 400.f), sf::Vector2f(250.f, 500.f)),
list(),
colision_manager()
{
    list.add(static_cast<Entity*>(&player));
    list.add(static_cast<Entity*>(&enemy));
    list.add(static_cast<Entity*>(&platform));
    list.add(static_cast<Entity*>(&platform1));
    list.add(static_cast<Entity*>(&platform2));

    colision_manager.add_player(&player);
    colision_manager.add_enemy(static_cast<Entity*>(&enemy));
    colision_manager.add_obstacle(static_cast<Entity*>(&platform));
    colision_manager.add_obstacle(static_cast<Entity*>(&platform1));
    colision_manager.add_obstacle(static_cast<Entity*>(&platform2));

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
        list.run();
        colision_manager.colide();
        //player.draw(&window);
        //enemy.draw(&window);
        //platform.draw(&window);
        list.draw(&window);

        window.display();
    }
}
