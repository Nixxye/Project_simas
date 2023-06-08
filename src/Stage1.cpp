#include "../stages/Stage1.h"

namespace Stages
{
    Stage1::Stage1():
    Stage(SAVE_STAGE_1, FILE_STAGE_1, SAVE_BASE_1, 1)
    {
        texture = pGM->load_textures("../assets/stage1.png");
        body.setTexture(texture);
        create_scenario(SCENARIO_FILE1);
    }
    Stage1::Stage1(int n_players):
    Stage(SAVE_STAGE_1, FILE_STAGE_1, SAVE_BASE_1, 6)
    {
        texture = pGM->load_textures("../assets/stage1.png");
        body.setTexture(texture);
        create_scenario(SCENARIO_FILE1);
    }
    
    Stage1::~Stage1()
    {
        if (loaded)
            save();
    }
    void Stage1::execute()
    {
        if (!loaded)
            load();
        players.execute();
        enemies.execute();
        obstacles.execute();
        colision_manager.colide();
        //draw();
        //else horrível
        if (pSM->get_CurrentStateID() == id_state)
        {
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> it = players.get_first();
            Entes::Characters:: Player* player1 = dynamic_cast<Entes::Characters::Player*>(*it);
            it++;
           // Entes::Characters:: Player* player2 = dynamic_cast<Entes::Characters::Player*>(*it);
            //std::cout<<players.get_size()<<std::endl;
            if (players.get_size()==1)
            {
                if(player1->get_win())
                {
                    player1->set_win(false);
                    pSM->set_CurrentState(2);
                    //pGM->reset_camera();
                }
                if ((*players.get_first())->get_alive())
                    pGM->center((*players.get_first())->get_position());
                else
                {
                     pSM->set_CurrentState(3);
                     pSM->reset_current_state(); // vai ser o gameover ou stage 2
                     pGM->reset_camera();
                }
                    
            }
            else 
            {
                Entes::Characters:: Player* player2 = dynamic_cast<Entes::Characters::Player*>(*it);
                if (player1->get_win() || player2->get_win())
                {
                    player1->set_win(false);
                    player2->set_win(false);
                    pSM->set_CurrentState(2);
                }
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
        else{}
            //pGM->reset_camera();
        players.draw();
        enemies.draw();
        obstacles.draw();
    }
    void Stage1::save()
    {
        std::ofstream players_file(PLAYER_FILE1);
        if (!players_file)
        {
            std::cout<<"Cannot players file"<<std::endl;
            exit(1);
        }
        players_file<<players.get_size()<<std::endl<<std::endl;
        players.save(players_file);
        players_file.close();   

        std::ofstream enemies_file(ENEMY_FILE1);
        if (!enemies_file)
        {
            std::cout<<"Cannot players file"<<std::endl;
            exit(1);
        }
        enemies_file<<enemies.get_size()<<std::endl<<std::endl;
        enemies.save(enemies_file);
        enemies_file.close();
    }
    void Stage1::load()
    {
        int n, alive, damage, life;
        float vx, vy, px, py, sizex, sizey;
        std::string line;

        std::ifstream players_file;

        if (id_state == 1)
                players_file.open(PLAYER_FILE1);
        if (id_state == 6)
            players_file.open(PLAYER_FILE2);

        if (!players_file)
        {
            std::cout<<"Cannot open players_file"<<std::endl;
            exit(1);
        }
        players_file >> n;

        for (int i = 0; i < n; i++)
        {
            players_file >> alive >> life >> px >> py >> vx >> vy >> sizex >> sizey;
            Entes::Characters::Player* player = new Entes::Characters::Player(i+1, (bool) alive, life, sf::Vector2f(px, py), sf::Vector2f(vx, vy), sf::Vector2f(sizex, sizey));
            add_player(player); 
        }

        std::ifstream enemies_file(ENEMY_FILE1);
        if (!enemies_file)
        {
            std::cout<<"Cannot open enemies_file"<<std::endl;
            exit(1);
        }
        enemies_file >> n;
        //std::cout<<"N de inimigos "<<n;
        for (int i = 0; i < n; i++)
        {
            create_enemy(enemies_file);
        }  
        //std::cout<<"Número de inimigos: "<<enemies.get_size()<<std::endl;
        //VAI SAIR:
        /*
        std::ifstream file2("../saves/stage1.dat");

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
            //std::cout<<"Obstacle added"<<std::endl;
        }
        file2.close();
        */
        loaded = true;
    }
    void Stage1::reset()
    {
         //Vai sair:
        if (loaded)
            players.clear();
        if (loaded)
            enemies.clear();

        int n, vx, vy, py, px, alive, damage, sizex, sizey, life;
        std::string line;

        std::ifstream players_file(PLAYER_RESET_FILE1);
        if (!players_file)
        {
            std::cout<<"Cannot open players_reset_file"<<std::endl;
            exit(1);
        }
        players_file >> n;

        std::cout<<"No reset do stage2"<<std::endl;
        for (int i = 0; i < n; i++)
        {
            players_file >> alive >> life >> px >> py >> vx >> vy >> sizex >> sizey;
            Entes::Characters::Player* player = new Entes::Characters::Player(i+1, (bool) alive, life, sf::Vector2f(px, py), sf::Vector2f(vx, vy), sf::Vector2f(sizex, sizey));
            add_player(player); 
        }

        std::ifstream enemies_file(ENEMY_RESET_FILE1);
        if (!enemies_file)
        {
            std::cout<<"Cannot open enemies_reset_file"<<std::endl;
            exit(1);
        }
        enemies_file >> n;
        
        for (int i = 0; i < n; i++)
        {
            getline(enemies_file, line);
            getline(enemies_file, line);
            create_enemy(enemies_file);
        }  
        //std::cout<<"Número de inimigos: "<<enemies.get_size()<<std::endl;      
        /*
        if (!loaded)
        {
                //VAI SAIR:
            std::ifstream file2("../saves/stage1.dat");

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
                //std::cout<<"Obstacle added"<<std::endl;
            }
            file2.close();
            */
            loaded = true;
    }        
}
