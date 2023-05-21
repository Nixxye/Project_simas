#include "../stages/Stage.h"
#include "Stage.h"

namespace Stages
{
    Stage::Stage(string savefile, string infofile):
    obstacles(),
    enemies(),
    players(),
    colision_manager(),
    events_manager(),
    save_file(savefile),
    stage_info(infofile)
    {
        load();
        colision_manager.set_enemy_list(&enemies);
        colision_manager.set_player_list(&players);
        colision_manager.set_obstacle_list(&obstacles);     
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
    
    void Stage::draw()
    {
        //N sei o q fazer aqui.
    }
    
    void Stage::add_enemy(Entity* enemy)
    {
        if (enemy)
        {
            enemies.add(enemy);
        }
    }
    void Stage::add_obstacle(Entity *obstacle)
    {
        if (obstacle)
        {
            obstacles.add(obstacle);
        }
    }
    void Stage::add_player(Entity *player)
    {
        if (player)
        {
            players.add(player);
            events_manager.set_player(player);
        }
    }
    void Stage::save()
    {
        ofstream file(save_file);
        if (!file)
        {
            cout<<"ERROR 1"<<endl;
            exit(1);
        }

        file <<"#players"<<endl;
        file <<players.get_size() << endl << endl;

        for (List<Entity>::Iterator<Entity> it = players.get_first(); it != nullptr; it++)
        {
            file << (*it)->get_id() <<endl<< (*it)->get_position().x << endl <<(*it)->get_position().y << endl<<(*it)->get_vel().x << endl<<(*it)->get_vel().y <<endl;
        }
        file << endl;

        file <<"#enemies"<<endl;

        file << enemies.get_size() << endl << endl;
        for (List<Entity>::Iterator<Entity> it = enemies.get_first(); it != nullptr; it++)
        {
            file << (*it)->get_id() <<endl<< (*it)->get_position().x << endl <<(*it)->get_position().y << endl<<(*it)->get_vel().x << endl<<(*it)->get_vel().y <<endl;
        }
        file << endl;
        /*
        file <<"#obstacles" <<endl;
        file << obstacles.get_size() << endl << endl;
        for (List<Entity>::Iterator<Entity> it = obstacles.get_first(); it != nullptr; it++)
        {
            file << (*it)->get_id() <<endl<< (*it)->get_position().x << endl <<(*it)->get_position().y << endl<<(*it)->get_vel().x << endl<<(*it)->get_vel().y <<endl;
        }
        file << endl;
        */
        file.close();
    }
    void Stage::load()
    {   
        ifstream file(save_file);
        int n = 0;
        Entity* aux = NULL;
        string line;

        if (!file)
        {
            cout <<"ERROR: 2"<<endl;
            exit(2); //exit
        }

        
        getline(file, line);
        if (line != "#players")
        {
            cout << "ERROR 4 "<< endl;
            file.close();
            exit(3);//exit
        }
        file >> n;
        getline(file, line);
        getline(file, line);
        for (int i = 0; i < n; i++)
        {
            int id;
            float posX, posY, velX, velY;

            file >> id >> posX >> posY >> velX >> velY;
            //cout << id << posX << posY << velX << velY << endl;
            getline(file, line);
            //Static cast;
            aux = new Player(sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), sf::Vector2f(50.f, 50.f));
            add_player(aux);
            //cout<<"LOADED"<<endl;
        }
        getline(file, line);
        getline(file, line);
        if (line != "#enemies")
        {
            cout << "ERROR 51 "<< endl;
            file.close();
            exit(3);//exit
        }
        file >> n;
        getline(file, line);
        getline(file, line);
        for (int i = 0; i < n; i++)
        {
            int id;
            float posX, posY, velX, velY;

            file >> id >> posX >> posY >> velX >> velY;
            //cout << id << posX << posY << velX << velY << endl;
            getline(file, line);
            //Static cast;
            aux = new Enemy(sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), sf::Vector2f(50.f, 50.f));
            add_enemy(aux);
            //cout<<"LOADED"<<endl;
        }
        file.close();


        ifstream file2(stage_info);

        if (!file2)
        {
            cout <<"ERROR: 4"<<endl;
            exit(2);
        }

        getline(file2, line);

        if (line != "#obstacles")
        {
            cout << "ERROR 6 "<< endl;
            file2.close();
            exit(3);
        }
        file2 >> n;

        getline(file2, line);
        getline(file2, line);
        for (int i = 0; i < n; i++)
        {
            int id;
            float posX, posY, sizeX, sizeY;

            file2 >> posX >> posY >> sizeX >> sizeY;
            //cout << id << posX << posY << velX << velY << endl;
            getline(file2, line);
            //Static cast;
            aux = new Obstacle(sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY));
            add_obstacle(aux);
            //cout<<"LOADED"<<endl;
        }
        file2.close();
    }
}
 