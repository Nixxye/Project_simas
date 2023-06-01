#include "../stages/Stage.h"

namespace Stages
{
    Stage::Stage(std::string savefile, std::string infofile, std::string savebase, int id):
    States::State(id),
    obstacles(),
    enemies(),
    players(),
    colision_manager(),
    save_file(savefile),
    stage_info(infofile),
    save_base(savebase)
    {
        load();
        colision_manager.set_enemy_list(&enemies);
        colision_manager.set_player_list(&players);
        colision_manager.set_obstacle_list(&obstacles);     
        events_manager = Managers::EventsManager::get_instance();

        pSObserver = new Observers::StageObserver(id);
        pSObserver->set_stage(this);
        setObservers();
    }

    Stage::~Stage()
    {
        save();
        if (pSObserver)
            delete pSObserver;
    }    
    void Stage::draw()
    {
        //N sei o q fazer aqui.
    }
    
    void Stage::add_enemy(Entes::Entity* enemy)
    {
        if (enemy)
        {
            enemies.add(enemy);
        }
    }
    void Stage::add_obstacle(Entes::Entity *obstacle)
    {
        if (obstacle)
        {
            obstacles.add(obstacle);
        }
    }
    void Stage::add_player(Entes::Entity *player)
    {
        if (player)
        {
            players.add(player);
            player->set_colision_manager(&colision_manager);
        }
    }
    void Stage::save()
    {
        std::ofstream file(save_file);
        if (!file)
        {
            std::cout<<"ERROR 1"<<std::endl;
            exit(1);
        }

        file <<"#players"<<std::endl;
        file <<players.get_size() << std::endl;

        for (Lists::List<Entes::Entity>::Iterator<Entes::Entity> it = players.get_first(); it != nullptr; it++)
        {
            file << std::endl;
            file << (*it)->get_id() <<std::endl<< (*it)->get_position().x << std::endl <<(*it)->get_position().y << std::endl<<(*it)->get_vel().x << std::endl<<(*it)->get_vel().y <<std::endl;
        }
        file << std::endl;

        file <<"#enemies"<<std::endl;

        file << enemies.get_size() << std::endl << std::endl;
        for (Lists::List<Entes::Entity>::Iterator<Entes::Entity> it = enemies.get_first(); it != nullptr; it++)
        {
            file << std::endl;
            file << (*it)->get_id() <<std::endl<< (*it)->get_position().x << std::endl <<(*it)->get_position().y << std::endl<<(*it)->get_vel().x << std::endl<<(*it)->get_vel().y <<std::endl<<std::endl;
        }
        file << std::endl;
        file.close();
    }
    void Stage::load()
    {   
        std::ifstream file(save_file);
        int n = 0;
        Entes::Entity* aux = NULL;
        std::string line;

        if (!file)
        {
            std::cout <<"ERROR: 2"<<std::endl;
            exit(2); //exit
        }

        
        getline(file, line);
        if (line != "#players")
        {
            std::cout << "ERROR 4 "<< std::endl;
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
            aux = new Entes::Characters::Player(i+1,sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), sf::Vector2f(50.f, 50.f));
            add_player(aux);
            //cout<<"LOADED"<<endl;
        }
        getline(file, line);
        getline(file, line);
        if (line != "#enemies")
        {
            std::cout << "ERROR 51 "<< std::endl;
            file.close();
            exit(3);//exit
        }
        file >> n;
        std::getline(file, line);
        std::getline(file, line);
        for (int i = 0; i < n; i++)
        {
            int id;
            float posX, posY, velX, velY;

            file >> id >> posX >> posY >> velX >> velY;
            //cout << id << posX << posY << velX << velY << endl;
            std::getline(file, line);
            //Static cast;
            aux = create_enemy(id, sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), sf::Vector2f(50.f, 50.f));
            add_enemy(aux);
            //cout<<"LOADED"<<endl;
        }
        file.close();


        std::ifstream file2(stage_info);

        if (!file2)
        {
            std::cout <<"ERROR: 4"<<std::endl;
            exit(2);
        }

        std::getline(file2, line);

        if (line != "#obstacles")
        {
            std::cout << "ERROR 6 "<< std::endl;
            file2.close();
            exit(3);
        }
        file2 >> n;

        std::getline(file2, line);
        std::getline(file2, line);
        for (int i = 0; i < n; i++)
        {
            int id;
            float posX, posY, sizeX, sizeY;

            file2 >> posX >> posY >> sizeX >> sizeY;
            //cout << id << posX << posY << velX << velY << endl;
            std::getline(file2, line);
            //Static cast;
            //Mudar dps o id:
            aux = new Entes::Obstacles::Obstacle(11, sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY));
            add_obstacle(aux);
            //cout<<"LOADED"<<endl;
        }
        file2.close();
    }
    void Stage::reset()
    {
        //std::cout<<"No reset"<<std::endl;
        enemies.clear();
        players.clear();
        //obstacles.clear();
        /*
        std::cout<<enemies.get_size()<<std::endl;
        std::cout<<players.get_size()<<std::endl;
        std::cout<<obstacles.get_size()<<std::endl;
        */
        std::ifstream file(save_base);
        int n = 0;
        Entes::Entity* aux = NULL;
        std::string line;

        if (!file)
        {
            std::cout <<"ERROR: 2"<<std::endl;
            exit(2); //exit
        }

        
        getline(file, line);
        if (line != "#players")
        {
            std::cout << "ERROR 4 "<< std::endl;
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
            aux = new Entes::Characters::Player(i + 1, sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), sf::Vector2f(50.f, 50.f));
            add_player(aux);
            //cout<<"LOADED"<<endl;
        }
        getline(file, line);
        getline(file, line);
        if (line != "#enemies")
        {
            std::cout << "ERROR: 53 "<< std::endl;
            file.close();
            exit(3);//exit
        }
        file >> n;
        std::getline(file, line);
        std::getline(file, line);
        for (int i = 0; i < n; i++)
        {
            int id;
            float posX, posY, velX, velY;

            file >> id >> posX >> posY >> velX >> velY;
            //cout << id << posX << posY << velX << velY << endl;
            std::getline(file, line);
            //Static cast;
            aux = create_enemy(id, sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), sf::Vector2f(50.f, 50.f));
            add_enemy(aux);
            //cout<<"LOADED"<<endl;
        }
        file.close();
    }

    void Stage::setObservers()
    {
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> aux = players.get_first();
        while(aux != nullptr)
        {
            pSObserver->add_player_observer((*aux)->get_observer());
            aux++; 
        }
    }

    Entes::Entity* Stage::create_enemy(int id, sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f size)
    {
        Entes::Entity* aux = NULL;
        switch (id)
        {
        case 1:
            aux = new Entes::Characters::Enemy1(pos, vel, size);
            break;
        case 2:
            aux = new Entes::Characters::Enemy2(pos, vel, size);
        case 3:
            aux = new Entes::Characters::Enemy3(pos, vel, size);
        default:
            break;
        }
        return aux;
    }
}
 