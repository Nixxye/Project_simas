#include "../stages/Stage.h"

namespace Stages
{
    Stage::Stage():
    obstacles(),
    enemies(),
    players(),
    colision_manager(),
    window(sf::VideoMode(WIDTH, HEIGHT), "Project Simas"),
    colision_manager()
    {
        load();
    }

    Stages::Stage::~Stage()
    {
        save();
    }
    void Stage::create_enemies()
    {
    }
    void Stage::create_obstacles()
    {
    }
    void Stage::add_enemy(Entity* enemy)
    {
        if (enemy)
        {
            enemies.add(enemy);
            colisionManager.add_enemy(enemy);
        }
    }
    void Stage::add_obstacle(Entity *obstacle)
    {
        if (obstacle)
        {
            enemies.add(obstacle);
            colisionManager.add_obstacle(obstacle);
        }
    }
    void Stage::add_player(Entity *player)
    {
        if (player)
        {
            enemies.add(player);
            colisionManager.add_player(player);
        }
    }
    void Stage::save()
    {
        ofstream file(filename);
        if (!filename)
            cout<<"ERROR"<<endl;

        file <<"#enemies"<<endl;
        file << enemies.get_size() << endl;

        for (List<Enemy>::Iterator<Enemy> it = enemies.get_first(); it != nullptr; it++)
        {
            file << (*it)->get_id() << " " << (*it)->get_position() << " " << (*it)->get_size() << " " << (*it)->get_vel() << (*it)->get_alive() << endl;
        }
    }
    void Stage::load()
    {   
        Entity* obstacle1 = new Obstacle();
        add_obstacle(obstacle1);

        Entity* player1 = new Player();
        add_player(player1);

        Entity* enemy1 = new Enemy();
        add_enemy(enemy1);
    }
}
 