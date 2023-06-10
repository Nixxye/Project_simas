#include "../entities/Player.h"
#include "../managers/ColisionManager.h"

namespace Entes
{
    namespace Characters
    {
        Player::Player(int index, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        attack_body(sf::Vector2f(size.x * 2, size.y * 2)),
        is_attacking(false),
        Character(0, pos, velocity, size),
        attack_delay(0),
        win(false),
        damage(0),
        player_id(index)
        {
            attack_body.setOrigin(attack_body.getSize().x / 2, attack_body.getSize().y / 2);
            //attack_body.setFillColor(sf::Color::Red);
            attack_body.setTexture(pGM->load_textures("../assets/teste1.png"));
            life = 20;
            //lives = 3;
            //pPObserver = new Observers::PlayerObserver(index);
            //std::cout<<"Added player "<<index<<std::endl;
            if (player_id == 1)
            {
                texture = pGM->load_textures("../assets/player.png");
            }
            else if (player_id == 2)
            {
                texture = pGM->load_textures("../assets/player2.png");
            }
            //pPObserver->set_player(this);

            body.setTexture(texture);

            std::cout<<body.getPosition().x<<" "<<body.getPosition().y<<std::endl;
        }
        Player::Player(int index, bool alv, int lf, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        attack_body(body.getSize() * 2.f),
        is_attacking(false),
        Character(0, pos, velocity, size),
        attack_delay(0),
        win(false),
        damage(0),
        player_id(index)
        {
            alive = alv;
            life = lf;

            attack_body.setOrigin(attack_body.getSize().x / 2, attack_body.getSize().y / 2);
            attack_body.setFillColor(sf::Color::Red);

            //pPObserver = new Observers::PlayerObserver(index);
            //std::cout<<"Added player "<<index<<std::endl;
            if (player_id == 1)
            {
                texture = pGM->load_textures("../assets/player.png");
            }
            else if (player_id == 2)
            {
                texture = pGM->load_textures("../assets/player2.png");
            }
            //pPObserver->set_player(this);

            body.setTexture(texture);
            std::cout<<body.getPosition().x<<" "<<body.getPosition().y<<std::endl;
        }

        Player::~Player()
        {

        }
        void Player::draw()
        {
            if (alive)
            {

                if (is_attacking)
                {
                    pGM->draw(&attack_body);
                    is_attacking = false;
                } 
                pGM->draw(&body);
            }         
        }

        void Player::execute()
        { 
            if (life < 0)
                alive = false;
            if (!alive)
            {
                //DAR UM JEITO DE FAZER UM GAME OVER DECENTE:
                //std::cout<<"Faleceu"<<std::endl;
                //exit(1);
            }
            move();
            attack();

            attack_delay--;
        }

        void Player::move(char direction)
        {
            if (player_id == 1)
            {     
                
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    if (vel.x <= VEL_MAX)
                        vel.x += 2*SPEED / slowed;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) //Left
                {
                    if (vel.x >= -VEL_MAX)
                        vel.x -= 2*SPEED / slowed;
                }
                else if (vel.x > 0)                               
                {
                    if (slowed > 1)
                        vel.x = 0;
                    else 
                        vel.x -= SPEED / 2;
                }
                else if (vel.x < 0)
                {
                    if (slowed > 1)
                        vel.x = 0;
                    else 
                        vel.x += SPEED / 2;
                }
            }
            if (player_id == 2)
            {
            
               if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))//Right
                {
                    if (vel.x <= VEL_MAX)
                        vel.x += 5*SPEED / slowed;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//Left
                {
                    if (vel.x >= -VEL_MAX)
                        vel.x -= 5*SPEED / slowed;
                }
                else if (slowed > 1)
                    vel.x = 0;
                //Frear:
                if (vel.x > 0)                               
                {
                    vel.x -= 4*SPEED;
                }
                else if (vel.x < 0)
                {
                    vel.x += 4*SPEED;
                }
            }
            if (vel.x <= SPEED/30 && vel.x >= -SPEED/30)
            {
                vel.x = 0.0;
            }
            if (!grounded)
            {
                if (slowed > 1)
                    vel.y += GRAVITY / 3;
                else 
                    vel.y += GRAVITY;
            }
            else if ( (player_id == 1 && sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ||
            (player_id == 2 && sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )) //Up
            {
                vel.y -= 10.f;
                body.setPosition(body.getPosition() + sf::Vector2f(0.f, 0.5));
            }
            //N sei pq a gravidade está mais rápida quando nos movemos; -> Gimmick
                //std::cout<<vel.x<<" "<<vel.y<<std::endl;
                body.setPosition(body.getPosition() + vel);
                player_position = body.getPosition();
                speed = (int) sqrt(vel.x*vel.x + vel.y*vel.y);   
            slowed = 1;
            //std::cout<<vel.y<<std::endl;
        }

        void Player::collide(Entity *other, std::string direction)
        {
            int index = other->get_id();
            //std::cout<<index<<std::endl;
            switch (index)
            {
            case 1:
                if (direction == "Above")
                {
                    vel.y = 40 * SPEED;
                    other->set_vel(sf::Vector2f(other->get_vel().x, -5 * SPEED));
                }
                else if (direction == "Below")
                {
                    grounded = true;
                    move('U');
                    vel.y *= -1;
                    other->set_vel(sf::Vector2f(other->get_vel().x, 5 * SPEED));
                }
                else if (direction == "Left")
                {
                    vel = sf::Vector2f(10*SPEED, vel.y);
                    other->set_vel(sf::Vector2f(-5 * SPEED, other->get_vel().y));
                }
                else if (direction == "Right")
                {
                    vel = sf::Vector2f(-10*SPEED, vel.y);
                    other->set_vel(sf::Vector2f(5 * SPEED, other->get_vel().y));
                }
                move();
                break;
                //Bullet:
            case 11:
                if (direction == "Below")
                {
                    vel = sf::Vector2f(vel.x, 0.f);
                }
                else if (direction == "Above")
                {
                    vel = sf::Vector2f(vel.x, 0.f);
                }
                else if (direction == "Left")
                {
                    vel = sf::Vector2f(-CR*vel.x, vel.y);  
 
                }
                else if (direction == "Right")
                {
                    vel = sf::Vector2f(-CR*vel.x, vel.y);
                }
                break;
            case 12:

                if (direction == "Below")
                {
                    vel = sf::Vector2f(vel.x, 0.f);
                }
                else if (direction == "Above")
                {
                    vel = sf::Vector2f(vel.x, 0.f);
                }
                else if (direction == "Left")
                {
                    vel = sf::Vector2f(-CR*vel.x, vel.y);  
 
                }
                else if (direction == "Right")
                {
                    vel = sf::Vector2f(-CR*vel.x, vel.y);
                }
                break;
            case 13:
                //std::cout<<"Espinho"<<std::endl;
                if (direction == "Below")
                {
                    vel = sf::Vector2f(vel.x, -5.f);
                }
                else if (direction == "Above")
                {
                    vel = sf::Vector2f(vel.x, 5.f);
                }
                else if (direction == "Left")
                {
                    vel = sf::Vector2f(5.f, vel.y);  
 
                }
                else if (direction == "Right")
                {
                    vel = sf::Vector2f(-5.f, vel.y);
                }
                move();
                break;
            }
            
        }

        void Player::attack()
        {
            //Pegar as teclas do player
            if ((player_id == 1 && !  sf::Keyboard::isKeyPressed(sf::Keyboard::Space))||
            (player_id == 2 && ! sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)))
            {
                return;
            }
            
            damage = DMG;
            is_attacking = true;
            if (attack_delay <= 0)
            {
                attack_delay = ATTACK_DELAY;
                std::string direction = " ";
                //std::cout<<"Attacking"<<std::endl;
                is_attacking = true;
                if (player_id == 1)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                    {
                        direction = "Above";
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                    {
                        direction = "Left";
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                    {
                        direction = "Right";
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                    {
                        direction = "Below";
                    }
                    else 
                    {
                        if (vel.x >= 0)
                            direction = "Right";
                        else 
                            direction = "Left";
                    }
                }
                else if (player_id == 2)
                {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        direction = "Above";
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        direction = "Left";
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        direction = "Right";
                    }
                    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        direction = "Below";
                    }
                    else 
                    {
                        if (vel.x >= 0)
                            direction = "Right";
                        else 
                            direction = "Left";
                    }
                }

                if (direction == "Above")
                {
                    attack_body.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y - body.getSize().y / 2 - attack_body.getSize().y / 2));
                }
                else if (direction == "Right")
                {
                   attack_body.setPosition(sf::Vector2f(body.getPosition().x + body.getSize().x / 2 + attack_body.getSize().x / 2, body.getPosition().y)); 
                }
                if (direction == "Below")
                {
                    attack_body.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y + body.getSize().y / 2 + attack_body.getSize().y / 2));
                }
                else if (direction == "Left")
                {
                   attack_body.setPosition(sf::Vector2f(body.getPosition().x - body.getSize().x / 2 - attack_body.getSize().x / 2, body.getPosition().y)); 
                }
                //std::cout<<"Attacking"<<std::endl;
                pGM->draw(&attack_body);
                colision_manager->collide_attack(static_cast<Player*>(this), direction);

                //Por enquanto is_attacking é inútil:
                //is_attacking = false;
            }
            damage = 0;
        }
        void Player::collide_attack(Entity *other, std::string direction)
        {
            other->inflict_damage(damage);
            //std::cout<<"Player indo para "<<direction<<std::endl;
            if(direction == "Left")
                vel = sf::Vector2f(RECOIL, vel.y);
            else if(direction == "Right")
                vel = sf::Vector2f(-RECOIL, vel.y);
            else if(direction == "Above")
                vel = sf::Vector2f(vel.x, RECOIL);
            else if(direction == "Below")
            {
                vel.y = - 10.f;
            }
        }
        void Player::set_slowed(int s)
        {
            slowed = s;
        }
        void Player::save(std::ofstream& file)
        {
            if (!file.is_open())
            {
                std::cout<<"Error: Cannot open player file!"<<std::endl;
                return;
            }
            //file<<id<<std::endl<<player_id<<std::endl;
            if (alive)
                file<<1<<std::endl;
            else
                file<<0<<std::endl;
            file<<life<<std::endl
            <<body.getPosition().x<<std::endl<<body.getPosition().y<<std::endl
            <<vel.x<<std::endl<<vel.y<<std::endl
            <<body.getSize().x<<std::endl<<body.getSize().y<<std::endl<<std::endl;
        }
    }
}
