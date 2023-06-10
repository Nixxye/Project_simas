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
    body(),
    loaded(false)
    {
        colision_manager.set_enemy_list(&enemies);
        colision_manager.set_player_list(&players);
        colision_manager.set_obstacle_list(&obstacles);     

        events_manager = Managers::EventsManager::get_instance();


    }

    Stage::~Stage()
    {
        //if (pSObserver)
            //delete pSObserver;
    }    
    void Stage::draw()
    {
        //N sei o q fazer aqui.
        pGM->draw(&(this->body));
        hud.draw();
    }
    
    void Stage::add_enemy(Entes::Entity* enemy)
    {
        if (enemy)
        {
            enemy->set_colision_manager(&colision_manager);
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
    Entes::Entity* Stage::create_enemy(std::ifstream& file)
    {
        Entes::Entity* aux = NULL;
        Entes::Entity* bullet = NULL;
        int index, alive, life;
        std::string line;
        float px, py, vx, vy, damage, sx, sy;
        int rnd;
        file >> index >> alive >> life >> damage >> px >> py >> vx >> vy;

        std::srand(std::time(NULL)); //aleatorio
        if (alive != 0 && alive != 1)
            rnd = rand() % alive;
        std::cout<<"--"<<index<<"--"<<std::endl;
        //FAZER STATIC CAST AQUI:
        switch (index)
        {
        case 1:
            int mc;
            file >> sx >> sy >> mc;
            aux = new Entes::Characters::Enemy1(!((bool) rnd), life, sf::Vector2f(px, py), sf::Vector2f(vx, vy), damage, sf::Vector2f(sx, sy), mc);
            break;
        case 2:
            float sensor_radius, axis_x, axis_y, burst, power;
            int attacking;
            file >> sx >> sy >> sensor_radius >> attacking >> axis_x >> axis_y >> burst >> power;
            aux = new Entes::Characters::Enemy2(!((bool) rnd), life, sf::Vector2f(px, py), sf::Vector2f(vx, vy), damage, sf::Vector2f(sx, sy), &players, sensor_radius, (bool) attacking, sf::Vector2f(axis_x, axis_y), burst, power);
            break;
        case 3:
            int attack_delay;
            file >> sx >> sy >> attack_delay;
            //std::cout<<px<<" "<<py<<" "<<vx<<" "<<vy<<" "<<sx<<" "<<sy;
            aux = new Entes::Characters::Boss(!((bool) rnd), life, sf::Vector2f(px, py), sf::Vector2f(vx, vy), damage, sf::Vector2f(sx, sy), attack_delay);
            int n; 
            file >> n;
            int r, lifetime, friendly;
            for (int i = 0; i < n; i++)
            {
                //std::cout<<"Creating bullet"<<std::endl;
                std::getline(file, line);
                std::getline(file, line);
                file >> index >> alive >> damage >> px >> py >> vx >> vy >> r >> lifetime >> friendly;
                //ler nova linha:
                bullet = new Entes::Bullet((bool) alive, sf::Vector2f(px, py), sf::Vector2f(vx, vy), damage, r, lifetime, (bool) friendly);
                static_cast<Entes::Characters::Boss*>(aux)->add_bullet(bullet);
                bullet->set_colision_manager(&colision_manager);
            }  
            break;       
        default:
            break;
        }
        //tirar o set colision_manager depois - > já está no add_enemy;
        aux->set_colision_manager(&colision_manager);
        add_enemy(static_cast<Entes::Entity*>(aux));
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
    void Stage::create_scenario(std::string file, std::string save)
    {
        std::ifstream input(file);
        std::ofstream output(save);

        if (!input)
        {
            std::cout<<"Missing scenario file"<<std::endl;
            exit(1);
        }
        if (!output)
        {
            std::cout<<"Cannot open scenario save file"<<std::endl;
            exit(1);
        }

        std::string line;
        Entes::Entity* aux = nullptr;
        int j = 0;
        std::srand(std::time(NULL)); //aleatorio
        int n_rand = 0;
        for (int i = 0; std::getline(input, line); i++)
        {
            j = 0;
            for (char character : line)  
            {
                switch (character)
                {
                //Plataforma:
                case '0':
                    aux = new Entes::Obstacles::Platform(sf::Vector2f(j * OBSTACLE_SIZE, i * OBSTACLE_SIZE));
                    add_obstacle(aux);
                    output << 0;
                    break;
                case '1':
                    aux = new Entes::Obstacles::Slime(sf::Vector2f(j * OBSTACLE_SIZE, i * OBSTACLE_SIZE));
                    add_obstacle(aux);
                    output << 1;
                    break;
                case '2':
                    aux = new Entes::Obstacles::Spike(sf::Vector2f(j * OBSTACLE_SIZE, i * OBSTACLE_SIZE));
                    add_obstacle(aux);
                    output << 2;
                    break;
                //aleatorio espinho
                case '6':
                    n_rand = rand() % 3;
                    aux = new Entes::Obstacles::Spike(sf::Vector2f(j * 50.f, i * 50.f));
                    if (n_rand != 0)
                    {
                        aux->set_alive(false);
                        output << ' ';
                    }
                    else 
                        output << 2;
                        
                    add_obstacle(aux);
                    break;
                case '7':
                    n_rand = rand() % 3;
                    aux = new Entes::Obstacles::Platform(sf::Vector2f(j * 50.f, i * 50.f));
                    if (n_rand != 0)
                    {
                        aux->set_alive(false);
                        output << ' ';
                    }
                    else 
                        output << 0;
                    add_obstacle(aux);
                    break;
                case '8':
                    n_rand = rand() % 3;
                    aux = new Entes::Obstacles::Slime(sf::Vector2f(j * 50.f, i * 50.f));
                    if (n_rand != 0)
                    {
                        aux->set_alive(false);
                        output << ' ';
                    }
                    else 
                        output << 1;
                    add_obstacle(aux);
                    break;
                case '5':
                    aux = new Entes::Obstacles::Platform(sf::Vector2f(j * OBSTACLE_SIZE, i * OBSTACLE_SIZE), true);
                    add_obstacle(aux);
                    output << 5;
                    break;                    
                default:
                    output << ' ';
                    break;
                }    
                j++;
            }
            output << std::endl;
        }
        input.close();
        output.close();
    }
    void Stage::load_scenario(std::string save_scenario_file)
    {
        if (obstacles.get_size() > 0)
            obstacles.clear();

        std::ifstream input(save_scenario_file);

        if (!input)
        {
            std::cout<<"Missing scenario file"<<std::endl;
            exit(1);
        }

        std::string line;
        Entes::Entity* aux = nullptr;
        int j = 0;

        for (int i = 0; std::getline(input, line); i++)
        {
            j = 0;
            for (char character : line)  
            {
                switch (character)
                {
                //Plataforma:
                case '0':
                    aux = new Entes::Obstacles::Platform(sf::Vector2f(j * OBSTACLE_SIZE, i * OBSTACLE_SIZE));
                    add_obstacle(aux);
                    break;
                case '1':
                    aux = new Entes::Obstacles::Slime(sf::Vector2f(j * OBSTACLE_SIZE, i * OBSTACLE_SIZE));
                    add_obstacle(aux);
                    break;
                case '2':
                    aux = new Entes::Obstacles::Spike(sf::Vector2f(j * OBSTACLE_SIZE, i * OBSTACLE_SIZE));
                    add_obstacle(aux);
                    break;
                case '5':
                    aux = new Entes::Obstacles::Platform(sf::Vector2f(j * OBSTACLE_SIZE, i * OBSTACLE_SIZE), true);
                    add_obstacle(aux);
                    break;                    
                }    
                j++;
            }
        }
        input.close();
    }
}
 