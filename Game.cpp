#include "Game.h"

Game::Game():
window(sf::VideoMode(WIDTH, HEIGHT), "Project Simas"),
player(),
enemy(),
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

        list.move();
        
        list.draw(&window);

        window.display();
    }
}
