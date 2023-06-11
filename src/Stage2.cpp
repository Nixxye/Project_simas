#include "../stages/Stage2.h"

namespace Stages
{
    Stage2::Stage2():
    Stage(2)
    {
        texture = pGM->load_textures("../assets/stage2.png");
        body.setTexture(texture);  
    }
    Stage2::Stage2(int n_players):
    Stage(5)
    {
        texture = pGM->load_textures("../assets/stage2.png");
        body.setTexture(texture);  
    }

    Stage2::~Stage2()
    {
        if (loaded)
            save();
    }
    void Stage2::execute()
    {
        if (!loaded)
        {
            load();
        }
        //std::cout<<"Testeee"<<std::endl;
        //draw();// Nao sei pq nao desenha o ataque
        players.execute();
        enemies.execute();
        obstacles.execute();
        hud.execute();

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
                    std::cout<<"Matou "<<enemies.get_nkilled()<<std::endl;
                    hud.add_points((int) (*players.get_first())->get_position().x + enemies.get_nkilled() * 1000);
                    pSM->set_CurrentState(3); // vai ser o gameover ou stage 2
                    pGM->reset_camera();
                    std::cout<<"Seu ruim"<<std::endl;
                }
                //std::cout<<(*players.get_first())->get_position().x<<" "<<(*players.get_first())->get_position().y<<std::endl;
                    
            }
            else 
            {
                //printf ("%d",players.get_size());
                if ((*players.get_first())->get_alive() && (*it)->get_alive())
                    pGM->center((*it)->get_position(),(*players.get_first())->get_position());
                else 
                {
                    std::cout<<"Matou "<<enemies.get_nkilled()<<std::endl;
                    hud.add_points((int) (*players.get_first())->get_position().x + enemies.get_nkilled() * 1000);
                    pSM->set_CurrentState(3);
                    pGM->reset_camera();
                }
                /*else if (!(*players.get_first())->get_alive() && !(*it)->get_alive())
                { 
                    pSM->set_CurrentState(3);
                    pGM->reset_camera();
                } 
                else if(!(*players.get_first())->get_alive())
                    pGM->center((*it)->get_position());
                else 
                    pGM->center((*players.get_first())->get_position());*/
            }
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> it_enemies;
            bool anyEnemyAlive = false;

                for (it_enemies = enemies.get_first(); it_enemies != nullptr; it_enemies++)
                {
                    if ((*it_enemies)->get_alive())
                    {
                        anyEnemyAlive = true;
                        break;
                    }
                }

                if (!anyEnemyAlive)
                {
                    std::cout<<"Matou "<<enemies.get_nkilled()<<std::endl;
                    hud.add_points((int) (*players.get_first())->get_position().x + enemies.get_nkilled() * 1000 + 3000);
                    Entes::Hud::set_win(true);
                    std::cout<<"Bacana"<<std::endl;
                    pSM->set_CurrentState(3);
                    pGM->reset_camera();
                }


        }
        else{}
           // pGM->reset_camera();
        players.draw();
        enemies.draw();
        //std::cout<<(*enemies.get_first())->get_size().x<<" "<<(*enemies.get_first())->get_size().y<<std::endl;
        obstacles.draw();
    }
    void Stage2::save()
    {
        std::ofstream players_file;
        std::ofstream enemies_file;
        if (id_state == 2)
        {
            players_file.open(PLAYER_FILE21);
            enemies_file.open(ENEMY_FILE21);
        }
        else if (id_state == 5)
        {
            players_file.open(PLAYER_FILE22);
            enemies_file.open(ENEMY_FILE22);
        }


        if (!players_file)
        {
            std::cout<<"Cannot players file"<<std::endl;
            //exit
            return;
        }
        players_file<<players.get_size()<<std::endl<<std::endl;
        players.save(players_file);
        players_file.close();   

        
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
        load_scenario(SAVE_SCENARIO2);

        int n, alive, damage, life;
        float vx, vy, px, py, sizex, sizey;
        std::string line;
        std::ifstream players_file;
        std::ifstream enemies_file;
        if (id_state == 2)
        {
            players_file.open(PLAYER_FILE21);
            enemies_file.open(ENEMY_FILE21);
        }
        if (id_state == 5)
        {
            players_file.open(PLAYER_FILE22);
            enemies_file.open(ENEMY_FILE22);
        }


        if (!players_file)
        {
            std::cout<<"Cannot open players_file Stage2"<<std::endl;
            exit(1);
        }
        players_file >> n;

        for (int i = 0; i < n; i++)
        {
            players_file >> alive >> life >> px >> py >> vx >> vy >> sizex >> sizey;
            Entes::Characters::Player* player = new Entes::Characters::Player(i+1, (bool) alive, life, sf::Vector2f(px, py), sf::Vector2f(vx, vy), sf::Vector2f(sizex, sizey));
            add_player(player); 
        }

        
        if (!enemies_file)
        {
            std::cout<<"Cannot open enemies_file Stage2 load"<<std::endl;
            exit(1);
        }
        enemies_file >> n;
       
        for (int i = 0; i < n; i++)
        {
            create_enemy(enemies_file);
        }  
        
        loaded = true;
    }
    void Stage2::reset()
    {
        //Vai sair:
        if (loaded)
            players.clear();
        if (loaded)
            enemies.clear();

        create_scenario(SCENARIO_FILE2, SAVE_SCENARIO2);
        int n, vx, vy, py, px, alive, damage, sizex, sizey, life;
        std::string line;

        std::ifstream players_file;
        std::ifstream enemies_file;
        if (id_state == 2)
        {
             players_file.open(PLAYER_RESET_FILE21);
             enemies_file.open(ENEMY_RESET_FILE21);
        }
        else if (id_state == 5)
        {
            players_file.open(PLAYER_RESET_FILE22);
            enemies_file.open(ENEMY_RESET_FILE22);
        }


        if (!players_file)
        {
            std::cout<<"Cannot open players_reset_file"<<std::endl;
            exit(1);
        }
        players_file >> n;

        for (int i = 0; i < n; i++)
        {
            players_file >> alive >> life >> px >> py >> vx >> vy >> sizex >> sizey;
            Entes::Characters::Player* player = new Entes::Characters::Player(i+1, (bool) alive, life, sf::Vector2f(px, py), sf::Vector2f(vx, vy), sf::Vector2f(sizex, sizey));
            add_player(player); 
        }


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

       loaded = true;
    }

}