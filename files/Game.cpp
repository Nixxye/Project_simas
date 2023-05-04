#include "../headers/Game.h"

Game::Game():
window(sf::VideoMode(WIDTH, HEIGHT), "Project Simas"),
player(),
enemy(),
platform(),
list()
{
    list.add(static_cast<Entity*>(&player));
    list.add(static_cast<Entity*>(&enemy));


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
        //player.draw(&window);
        //enemy.draw(&window);
        platform.draw(&window);
        list.draw(&window);

        window.display();
    }
}
