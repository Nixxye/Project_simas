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
        damage(0)
        {
            attack_body.setOrigin(attack_body.getSize().x / 2, attack_body.getSize().y / 2);
            //attack_body.setFillColor(sf::Color::Red);
            attack_body.setTexture(pGM->load_textures("../assets/teste1.png"));
            life = 20;
            //lives = 3;
            //pPObserver = new Observers::PlayerObserver(index);
            //std::cout<<"Added player "<<index<<std::endl;
            if (index == 1)
            {
                texture = pGM->load_textures("../assets/player.png");
                player_id = 1; 
            }
            else if (index == 2)
            {
                texture = pGM->load_textures("../assets/player2.png");
                player_id = 2; 
            }
            //pPObserver->set_player(this);

            body.setTexture(texture);
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
            std::cout<<"PID"<<player_id<<std::endl;
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
                    if (slowed)
                        vel.x = 0;
                    else 
                        vel.x -= SPEED / 2;
                }
                else if (vel.x < 0)
                {
                    if (slowed)
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
                        vel.x += 2*SPEED / slowed;
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))//Left
                {
                    if (vel.x >= -VEL_MAX)
                        vel.x -= 2*SPEED / slowed;
                }
                else if (vel.x > 0)                               
                {
                    if (slowed)
                        vel.x = 0;
                    else 
                        vel.x -= SPEED / 2;
                }
                else if (vel.x < 0)
                {
                    if (slowed)
                        vel.x = 0;
                    else 
                        vel.x += SPEED / 2;
                }
            }
            if (vel.x <= SPEED/2 && vel.x >= -SPEED/2)
            {
                vel.x = 0.0;
            }
            if (!grounded)
            {
                if (slowed > 1)
                    vel.y += G / 3;
                else 
                    vel.y += G;
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
            //colisão bolas do barreto:
            //int dmg = other->get_damage(); -> quem dá dano são as plataformas;
            switch (index)
            {
            case 1:
                //Tirar o dano daqui e colocar nas plataformas -> coesão e desacoplamento:
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
                std::cout<<"Player: "<<life<<std::endl;
                move();
                break;
                //Bullet:
            case 4:
                break;
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
    }
}
