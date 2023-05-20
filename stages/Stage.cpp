#include "../stages/Stage.h"
#include "Stage.h"

namespace Stages
{
    Stage::Stage(string file):
    obstacles(),
    enemies(),
    players(),
    colision_manager(),
    events_manager(),
    window(sf::VideoMode(WIDTH, HEIGHT), "Project Simas"),
    filename(file)
    {
        window.setFramerateLimit(60);
        load();
        //ARRUMAR O DELETE DA LIST: COMO O MESMO PERSONAGEM ESTÁ EM MAIS DE UMA LISTA, PRECISA CHAMAR APENAS UM DELETE;       
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
    void Stage::draw(sf::RenderWindow* window)
    {
        //N sei o q fazer aqui.
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
            events_manager.set_player(player);
        }
    }
    void Stage::save()
    {
        ofstream file(filename);
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

        file <<"#obstacles" <<endl;
        file << obstacles.get_size() << endl << endl;
        for (List<Entity>::Iterator<Entity> it = obstacles.get_first(); it != nullptr; it++)
        {
            file << (*it)->get_id() <<endl<< (*it)->get_position().x << endl <<(*it)->get_position().y << endl<<(*it)->get_vel().x << endl<<(*it)->get_vel().y <<endl;
        }
        file << endl;
        
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
            cout <<"ERROR: 2"<<endl;
            exit(2); //exit
        }

        
        getline(file, line);
        if (line != "#players")
        {
            cout << "ERROR 3 "<< endl;
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
            cout << id << posX << posY << velX << velY << endl;
            getline(file, line);
            //Static cast;
            aux = new Player(sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), sf::Vector2f(50.f, 50.f));
            add_player(aux);
            cout<<"LOADED"<<endl;
        }
        getline(file, line);
        getline(file, line);
        if (line != "#enemies")
        {
            cout << "ERROR 3 "<< endl;
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
            cout << id << posX << posY << velX << velY << endl;
            getline(file, line);
            //Static cast;
            aux = new Enemy(sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), sf::Vector2f(50.f, 50.f));
            add_enemy(aux);
            cout<<"LOADED"<<endl;
        }
        getline(file, line);
        getline(file, line);
        if (line != "#obstacles")
        {
            cout << "ERROR 3 "<< endl;
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
            cout << id << posX << posY << velX << velY << endl;
            getline(file, line);
            //Static cast;
            aux = new Obstacle(sf::Vector2f(posX, posY), sf::Vector2f(800.f, 50.f));
            add_obstacle(aux);
            cout<<"LOADED"<<endl;
        }
        file.close();
    }
}
 