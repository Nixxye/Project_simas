#include "../stages/Stage1.h"

namespace Stages
{
    Stage1::Stage1():
    Stage(SAVE_STAGE_1, FILE_STAGE_1, SAVE_BASE_1, 1)
    {
                //Tamanho da primeira fase:
        body.setSize(sf::Vector2f(9800.f, 700.f));
        body.setOrigin(sf::Vector2f(0.f, -200.f));
        texture = pGM->load_textures("../assets/stage1.png");
        body.setTexture(texture);
    }
    Stage1::Stage1(int n_players):
    Stage(SAVE_STAGE_1, FILE_STAGE_1, SAVE_BASE_1, 6)
    {
        texture = pGM->load_textures("../assets/stage1.jpeg");
        body.setTexture(texture);
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
        draw();
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
                    pSM->reset_current_state();
                    //pGM->reset_camera();
                }
                if ((*players.get_first())->get_alive())
                    pGM->center((*players.get_first())->get_position());
                else
                {
                    std::cout<<"Matou "<<enemies.get_nkilled()<<std::endl;
                    hud.add_points((int) (*players.get_first())->get_position().x + enemies.get_nkilled() * 1000);
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
                    //Talvez n sirva pra nada;
                    player1->set_win(false);
                    player2->set_win(false);
                    pSM->set_CurrentState(5);
                    pSM->reset_current_state();

                }
                if ((*players.get_first())->get_alive() && (*it)->get_alive())
                    pGM->center((*it)->get_position(),(*players.get_first())->get_position());
                else
                {
                    hud.add_points((int) (*players.get_first())->get_position().x + enemies.get_nkilled() * 1000);
                    pSM->set_CurrentState(3);
                    pGM->reset_camera();
                }   
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
        std::ofstream players_file;
        std::ofstream enemies_file;
        if (id_state == 1)
        {
            players_file.open(PLAYER_FILE11);
            enemies_file.open(ENEMY_FILE11);
        }
        else if (id_state == 6)
        {
            players_file.open(PLAYER_FILE12);
            enemies_file.open(ENEMY_FILE12);
        }

        if (!players_file)
        {
            std::cout<<"Cannot players file"<<std::endl;
            exit(1);
        }
        players_file<<players.get_size()<<std::endl<<std::endl;
        
        players.save(players_file);
        players_file.close(); 


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
        load_scenario(SAVE_SCENARIO1);

        int n, alive, damage, life;
        float vx, vy, px, py, sizex, sizey;
        std::string line;

        std::ifstream players_file;
         std::ifstream enemies_file;

        if (id_state == 1)
        {
             players_file.open(PLAYER_FILE11);
             enemies_file.open(ENEMY_FILE11);

        }
        else if (id_state == 6)
        {
            players_file.open(PLAYER_FILE12);
            enemies_file.open(ENEMY_FILE12);
        }

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

       
        if (!enemies_file)
        {
            std::cout<<"Cannot open enemies_file Stage 1 load"<<std::endl;
            exit(1);
        }
        enemies_file >> n;
        //std::cout<<"N de inimigos "<<n;
        for (int i = 0; i < n; i++)
        {
            create_enemy(enemies_file);
        }  
        loaded = true;
    }
    void Stage1::reset()
    {
        create_scenario(SCENARIO_FILE1, SAVE_SCENARIO1);
         //Vai sair:
        if (loaded)
            players.clear();
        if (loaded)
            enemies.clear();

        int n, vx, vy, py, px, alive, damage, sizex, sizey, life;
        std::string line;

        std::ifstream players_file;
        std::ifstream enemies_file;
        if (id_state == 1)
        {
             players_file.open(PLAYER_RESET_FILE11);
             enemies_file.open(ENEMY_RESET_FILE11);
        }
        else if (id_state == 6)
        {
            players_file.open(PLAYER_RESET_FILE12);
            enemies_file.open(ENEMY_RESET_FILE12);
        }
        
        if (!players_file)
        {
            std::cout<<"Cannot open players_reset_file"<<std::endl;
            exit(1);
        }
        players_file >> n;

        std::cout<<"No reset do stage1"<<std::endl;
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
