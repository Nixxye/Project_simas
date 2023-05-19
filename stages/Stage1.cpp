#include "../stages/Stage1.h"

namespace Stages
{
    Stage1::Stage1():
    Stage(FILE_STAGE_1)
    {
        run();
    }

    Stage1::~Stage1()
    {
    }
    void Stage1::run()
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

            players.run();
            enemies.run();
            obstacles.run();

            colision_manager.colide();

            players.draw(&window);
            enemies.draw(&window);
            obstacles.draw(&window);
            
            window.display();
        }
    }
    void Stage1::create_enemies()
    {
    }
    void Stage1::create_obstacles()
    {
    }
}
