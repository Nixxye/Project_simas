#include "../stages/Stage2.h"

namespace Stages
{
    Stage2::Stage2():
    Stage(SAVE_STAGE_2, FILE_STAGE_2, SAVE_BASE_2, 2)
    {
        texture = pGM->load_textures("../assets/stage2.png");
        body.setTexture(texture);  
        load();   
    }

    Stage2::~Stage2()
    {
        save();
    }
    void Stage2::execute()
    {
    
        //std::cout<<"Testeee"<<std::endl;
        //draw();// Nao sei pq nao desenha o ataque
        players.execute();
        enemies.execute();
        obstacles.execute();

        colision_manager.colide();
        //draw();
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
    void Stage2::save()
    {
        std::ofstream players_file(PLAYER_FILE2);
        if (!players_file)
        {
            std::cout<<"Cannot players file"<<std::endl;
            //exit
            return;
        }
        players_file<<players.get_size()<<std::endl<<std::endl;
        players.save(players_file);
        players_file.close();   

        std::ofstream enemies_file(ENEMY_FILE2);
        if (!enemies_file)
        {
            std::cout<<"Cannot players file"<<std::endl;
            //exit
            return;
        }
        enemies_file<<enemies.get_size()<<std::endl<<std::endl;
        enemies.save(enemies_file);
        enemies_file.close();   
    }
    void Stage2::load()
    {
        std::ifstream players_file(PLAYER_FILE2);
        
        int n, vx, vy, py, px, alive, damage, sizex, sizey;
        std::string line;

        players_file >> n;

        getline(players_file, line);
        
        for (int i = 0; i < n; i++)
        {
            players_file >> alive >> damage >> px >> py >> vx >> vy >> sizex >> sizey;
            Entes::Characters::Player* player = new Entes::Characters::Player(i+1, sf::Vector2f(px, py), sf::Vector2f(vx, vy), sf::Vector2f(sizex, sizey));
            //set_damage();
            add_player(player); 
        }
            
        //VAI SAIR:
        std::ifstream file2("../saves/stage2.dat");

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
}