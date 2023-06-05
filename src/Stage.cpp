#include "../stages/Stage.h"

//PODE APAGAR TUDO RELACIONADO À LISTA DE BALAS AQUI:

namespace Stages
{
    Stage::Stage(std::string savefile, std::string infofile, std::string savebase, int id):
    States::State(id),
    obstacles(),
    enemies(),
    players(),
    bullets(),
    colision_manager(),
    save_file(savefile),
    stage_info(infofile),
    save_base(savebase),
    body()
    {
        
        
        load();
        colision_manager.set_enemy_list(&enemies);
        colision_manager.set_player_list(&players);
        colision_manager.set_obstacle_list(&obstacles);     
        //colision_manager.set_bullet_list(&bullets);

        events_manager = Managers::EventsManager::get_instance();

        pSObserver = new Observers::StageObserver(id);

        body.setSize(sf::Vector2f(1600000.f, 120000.f));
        body.setOrigin(sf::Vector2f(0.f, 215.f));


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
        pGM->draw(&(this->body));
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
    void Stage::add_bullet(Entes::Entity* bullet)
    {
        if (bullet)
        {
            bullets.add(bullet);
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

        file << enemies.get_size() << std::endl;
        for (Lists::List<Entes::Entity>::Iterator<Entes::Entity> it = enemies.get_first(); it != nullptr; it++)
        {
            file << std::endl;
            file << (*it)->get_id() <<std::endl<< (*it)->get_position().x << std::endl <<(*it)->get_position().y << std::endl<<(*it)->get_vel().x << std::endl<<(*it)->get_vel().y <<std::endl;

            if ((*it)->get_id() == 3)
            {
                Entes::Characters::Boss * boss = static_cast<Entes::Characters::Boss *>(*it);
                

                file <<std::endl;
                file <<"#bullets"<<std::endl;
                file << boss->get_n_bullets() << std::endl;
                //std::cout<<"n_bullets"<<boss->get_n_bullets()<<std::endl;
                for (Lists::List<Entes::Entity>::Iterator<Entes::Entity> bullets_it = boss->get_bullets(); bullets_it != nullptr; bullets_it++)
                {
                    file << std::endl;
                    file << (*bullets_it)->get_id() <<std::endl<< (*bullets_it)->get_position().x << std::endl <<(*bullets_it)->get_position().y << std::endl<<(*bullets_it)->get_vel().x << std::endl<<(*bullets_it)->get_vel().y << (static_cast<Entes::Bullet*>(*bullets_it))->get_lifetime()<<std::endl;  
                    //std::cout<<"Salvou 1 bala"<<std::endl;
                }
            }
            //std::cout<<"Saiu do save"<<std::endl;
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
            if (id == 3)
            {
                getline(file, line);
                getline(file, line);
                if (line != "#bullets")
                {
                    std::cout << "ERROR 57 "<< std::endl;
                    file.close();
                    exit(3);//exit
                }   
                int n_bullets;
                float lifetime;
                Entes::Entity* bullet = NULL;

                file >> n_bullets;
                std::getline(file, line);
                std::getline(file, line);
                //std::cout<<"n_bullets "<<n_bullets<<std::endl;
                for (int j = 0; j < n_bullets; j++)
                {
                    file >> id >> posX >> posY >> velX >> velY >> lifetime;
                    std::getline(file, line);
                    bullet = create_bullet(id, sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), lifetime, aux);

                    //add_bullet(bullet);
                    //std::cout<<"LOADED"<<std::endl;
                }

            }
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
            //std::cout<<"Aqui "<<stage_info<<std::endl;
            int id;
            float posX, posY, sizeX, sizeY;

            file2 >> id >> posX >> posY >> sizeX >> sizeY;
            //cout << id << posX << posY << velX << velY << endl;
            std::getline(file2, line);
            //Static cast;
            //Mudar dps o id:
            add_obstacle(create_obstacle(id, sf::Vector2f(posX, posY), sf::Vector2f(sizeX, sizeY)));
            //std::cout<<"LOADED"<<std::endl;
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
            aux->set_colision_manager(&colision_manager);
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
            if (id == 3)
            {
                getline(file, line);
                getline(file, line);
                if (line != "#bullets")
                {
                    std::cout << "ERROR 57 "<< std::endl;
                    file.close();
                    exit(3);//exit
                }   
                int n_bullets;
                float lifetime;
                Entes::Entity* bullet = NULL;

                file >> n_bullets;
                std::getline(file, line);
                std::getline(file, line);
                //std::cout<<"n_bullets "<<n_bullets<<std::endl;
                for (int j = 0; j < n_bullets; j++)
                {
                    file >> id >> posX >> posY >> velX >> velY >> lifetime;
                    std::getline(file, line);
                    bullet = create_bullet(id, sf::Vector2f(posX, posY), sf::Vector2f(velX, velY), lifetime, aux);
                    //add_bullet(bullet);
                    //std::cout<<"LOADED"<<std::endl;
                }

            }
            //cout<<"LOADED"<<endl;
        }
        file.close();
    }


    Entes::Entity* Stage::create_enemy(int id, sf::Vector2f pos, sf::Vector2f vel, sf::Vector2f size)
    {
        Entes::Entity* aux = NULL;
        std::cout<<"Index: "<<id<<std::endl;
        switch (id)
        {
        case 1:
            aux = new Entes::Characters::Enemy1(pos, vel, size);
            break;
        case 2:
            aux = new Entes::Characters::Enemy2(pos, vel, size, &players);
            std::cout<<"Cianoooo"<<std::endl;
            break;
        case 3:
            aux = new Entes::Characters::Boss(pos, vel, size);
        default:
            break;
        }
        aux->set_colision_manager(&colision_manager);
        return static_cast<Entes::Entity*>(aux);
    }

    Entes::Entity* Stage::create_bullet(int id, sf::Vector2f pos, sf::Vector2f vel, float lifetime, Entes::Entity* boss)
    {
        Entes::Characters::Boss* pBoss = static_cast<Entes::Characters::Boss*>(boss);
        Entes::Entity* bullet = NULL;
        //std::cout<<"N de balas "<<pBoss->get_n_bullets()<<std::endl;
        bullet = new Entes::Bullet(pos, vel, lifetime);
        bullet->set_colision_manager(&colision_manager);

        pBoss->add_bullet(static_cast<Entes::Entity*>(bullet));
        return static_cast<Entes::Entity*>(bullet);
    }
    Entes::Entity* Stage::create_obstacle(int id, sf::Vector2f pos, sf::Vector2f size)
    {
        Entes::Entity* aux = NULL;
        switch (id)
        {
        case 11:
            aux = static_cast<Entes::Entity*>(new Entes::Obstacles::Platform(pos, size));
            break;
        case 12:
            aux = static_cast<Entes::Entity*>(new Entes::Obstacles::Slime(pos, size));
            break;
        case 13:
            aux = static_cast<Entes::Entity*>(new Entes::Obstacles::Spike(pos, size));
        default:
            break;
        }
        aux->set_colision_manager(&colision_manager);
        return aux;
    }
    void Stage::execute()
    {
                //std::cout<<"Testeee"<<std::endl;
        //pGM->clean();
        draw();
        players.execute();
        enemies.execute();
        obstacles.execute();
        
        colision_manager.colide();
        
        //else horrível
        if (pSM->get_CurrentStateID() == id_state)
        {
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> it = players.get_first();
            it++;
            //std::cout<<players.get_size()<<std::endl;
            if (players.get_size()==1)
            {
                if ((*players.get_first())->get_alive())
                    pGM->center((*players.get_first())->get_position());
                else
                {
                     pSM->set_CurrentState(3); // vai ser o gameover ou stage 2
                     pGM->reset_camera();
                }
                    
            }
            else 
            {
                //printf ("%d",players.get_size());
                if ((*players.get_first())->get_alive() && (*it)->get_alive())
                    pGM->center((*it)->get_position(),(*players.get_first())->get_position());
                else if (!(*players.get_first())->get_alive() && !(*it)->get_alive()) 
                    pSM->set_CurrentState(3); // mudar para o gameover
                else if(!(*players.get_first())->get_alive())
                    pGM->center((*it)->get_position());
                else 
                    pGM->center((*players.get_first())->get_position());
            }
        }
        else
            pGM->reset_camera();

        players.draw();
        enemies.draw();
        obstacles.draw();
    }
}
 