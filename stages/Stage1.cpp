#include "../stages/Stage1.h"

namespace Stages
{
    Stage1::Stage1():
    Stage(SAVE_STAGE_1, FILE_STAGE_1)
    {

    }

    Stage1::~Stage1()
    {
    }
    void Stage1::run()
    {
        //Arrumar o código com o gerenciador de eventos e gráfico:
        //Feio, horrível, pavoroso, tira daqui!
        sf::Event event;
        events_manager.move_players(event);
        players.run();
        enemies.run();
        obstacles.run();

        colision_manager.colide();
        graphics_manager->center((*players.get_first())->get_position());
        players.draw();
        enemies.draw();
        obstacles.draw();
    }
    void Stage1::create_enemies()
    {
    }
    void Stage1::create_obstacles()
    {
    }
}
