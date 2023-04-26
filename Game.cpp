#include "Game.h"

Game::Game():
window(sf::VideoMode(WIDTH, HEIGHT), "Project Simas"),
player()
{
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
        player.move();
        player.draw(&window);
        window.display();
    }
}
