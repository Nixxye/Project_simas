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
        attack_delay(0)
        {
            attack_body.setOrigin(attack_body.getSize().x / 2, attack_body.getSize().y / 2);
            life = 20;
            damage = 0;
            //lives = 3;
            pPObserver = new Observers::PlayerObserver(index);
            //std::cout<<"Added player "<<index<<std::endl;
            if (index == 1)
            {
                texture = pGM->load_textures("../assets/player.png");
            }
            else if (index == 2)
            {
                texture = pGM->load_textures("../assets/player2.png");
            }
            pPObserver->set_player(this);

            body.setTexture(texture);
        }

        Player::~Player()
        {
            if(pPObserver)
                delete pPObserver;
            pPObserver = nullptr;
        }
        void Player::run()
        { 
            if (life < 0)
                alive = false;
            if (!alive)
            {
                //DAR UM JEITO DE FAZER UM GAME OVER DECENTE:
                std::cout<<"Faleceu"<<std::endl;
                //exit(1);
            }
            move();
            attack_delay--;
        }

        void Player::move(char direction)
        {
            if (direction == 'R') //Right
            {
                vel.x += 2*SPEED;
            }
            else if (direction == 'L') //Left
            {
                vel.x -= 2*SPEED;
            }
            else if (vel.x > 0)                               
            {
                vel.x -= SPEED / 2;
            }
            else if (vel.x < 0)
            {
                vel.x += SPEED / 2;
            }

            if (vel.x <= SPEED/2 && vel.x >= -SPEED/2)
            {
                vel.x = 0.0;
            }
            if (!grounded)
            {
                if (direction == '0')
                    vel.y += G;
            }
            else if (direction == 'U') //Up
            {
                vel.y -= 10.f;
                body.setPosition(body.getPosition() + sf::Vector2f(0.f, 0.5));
            }
            //N sei pq a gravidade está mais rápida quando nos movemos; -> Gimmick
            if (direction == '0')
            {
                //std::cout<<vel.x<<" "<<vel.y<<std::endl;
                body.setPosition(body.getPosition() + vel);
                player_position = body.getPosition();
                speed = (int) sqrt(vel.x*vel.x + vel.y*vel.y);   
            }
            //std::cout<<vel.y<<std::endl;
        }

        void Player::collide(Entity *other, std::string direction)
        {
            int index = other->get_id();
            //colisão bolas do barreto:
            int dmg = other->get_damage();
            switch (index)
            {
            case 1:
                if (dmg)
                {
                    life -= dmg;
                    if (direction == "Above")
                    {
                        life -= dmg;
                        vel.y = 40 * SPEED;
                        other->set_vel(sf::Vector2f(other->get_vel().x, -5 * SPEED));
                    }
                    else if (direction == "Below")
                    {
                        grounded = true;
                        move('U');
                        vel = sf::Vector2f(vel.x, -vel.y);
                        other->set_vel(sf::Vector2f(other->get_vel().x, 5 * SPEED));
                    }
                    else if (direction == "Left")
                    {
                        life -= dmg;
                        vel = sf::Vector2f(-vel.x, vel.y);
                        other->set_vel(sf::Vector2f(-5 * SPEED, other->get_vel().y));
                    }
                    else if (direction == "Right")
                    {
                        life -= dmg;
                        vel = sf::Vector2f(-vel.x, vel.y);
                        other->set_vel(sf::Vector2f(5 * SPEED, other->get_vel().y));
                    }
                    std::cout<<"Player: "<<life<<std::endl;
                    move();
                }
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
            }
            
        }

        void Player::attack()
        {
            //Pegar as teclas do player
            damage = DMG;
            if (attack_delay <= 0)
            {
                attack_delay = ATTACK_DELAY;
                std::string direction = " ";
                std::cout<<"Attacking"<<std::endl;
                is_attacking = true;

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
                    direction = "Down";
                }
                else 
                {
                    if (vel.x >= 0)
                        direction = "Right";
                    else 
                        direction = "Left";
                }
                if (direction == "Above")
                {
                    attack_body.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y - body.getSize().y / 2 - attack_body.getSize().y / 2));
                }
                else if (direction == "Right")
                {
                   attack_body.setPosition(sf::Vector2f(body.getPosition().x + body.getSize().x / 2 + attack_body.getSize().x / 2, body.getPosition().y)); 
                }
                if (direction == "Down")
                {
                    attack_body.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y + body.getSize().y / 2 + attack_body.getSize().y / 2));
                }
                else if (direction == "Left")
                {
                   attack_body.setPosition(sf::Vector2f(body.getPosition().x - body.getSize().x / 2 - attack_body.getSize().x / 2, body.getPosition().y)); 
                }
                
                pGM->draw(&attack_body);

                if(colision_manager->collide_attack(this, direction))
                {
                    if(direction == "Left")
                        vel = sf::Vector2f(RECOIL, vel.y);
                    else if(direction == "Right")
                        vel = sf::Vector2f(-RECOIL, vel.y);
                    else if(direction == "Above")
                        vel = sf::Vector2f(vel.x, -RECOIL);
                    else if(direction == "Right")
                        vel = sf::Vector2f(vel.x, RECOIL);
                
                }

                //Por enquanto is_attacking é inútil:
                is_attacking = false;
            }
            damage = 0;
        }
    }
}
