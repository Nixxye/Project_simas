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
    //Colocar o loop na principal
    void Stage1::run()
    {
        //Arrumar o código com o gerenciador de eventos e gráfico:
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();

            events_manager.move_players(sf::Event::KeyPressed);
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
