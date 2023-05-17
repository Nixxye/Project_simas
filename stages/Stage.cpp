#include "../stages/Stage.h"

namespace Stages
{
    Stage::Stage(string file):
    obstacles(),
    enemies(),
    players(),
    colision_manager(),
    window(sf::VideoMode(WIDTH, HEIGHT), "Project Simas"),
    filename(file)
    {
        window.setFramerateLimit(60);
        load();

        Entity* obstacle1 = new Obstacle();
        add_obstacle(obstacle1);

        Entity* player1 = new Player();
        add_player(player1);
        /*
        Entity* enemy1 = new Enemy();
        add_enemy(enemy1);
        */
    }

    Stage::~Stage()
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
            colision_manager.add_enemy(enemy);
        }
    }
    void Stage::add_obstacle(Entity *obstacle)
    {
        if (obstacle)
        {
            obstacles.add(obstacle);
            colision_manager.add_obstacle(obstacle);
        }
    }
    void Stage::add_player(Entity *player)
    {
        if (player)
        {
            players.add(player);
            colision_manager.add_player(player);
        }
    }
    void Stage::save()
    {
        ofstream file(filename);
        if (!file)
        {
            cout<<"ERROR 1"<<endl;
            return;
        }


        file <<"#enemies"<<endl;

        file << enemies.get_size() << endl << endl;
        for (List<Entity>::Iterator<Entity> it = enemies.get_first(); it != nullptr; it++)
        {
            file << (*it)->get_id() << " " << (*it)->get_position().x << " " << (*it)->get_position().y << " " << (*it)->get_vel().x << " " << (*it)->get_vel().y <<endl;
        }
        file.close();
    }
    void Stage::load()
    {   
        ifstream file(filename);
        int n = 0;
        Entity* aux = NULL;
        string line;

        if (!file)
        {
            cerr <<"ERROR: "<<filename<<endl;
            return; //exit
        }

        
        getline(file, line);
        if (line != "#enemies")
        {
            cout << "ERROR 3 "<< endl;
            file.close();
            return;//exit
        }
        file >> n;
        getline(file, line);
        for (int i = 0; i < n; i++)
        {
            int id;
            float posX, posY, velX, velY;

            file >> id >> posX >> posY >> velX >> velY;
            cout << id << " " << posX << " " << posY << " " << velX << " " << velY << endl;
            getline(file, line);
            //Static cast;
            aux = new Enemy(sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), sf::Vector2f(50.f, 50.f));
            add_enemy(aux);
        }

        Entity* obstacle1 = new Obstacle();
        add_obstacle(obstacle1);

        Entity* player1 = new Player();
        add_player(player1);
        /*
        Entity* enemy1 = new Enemy();
        add_enemy(enemy1);
        */
    }
}
 