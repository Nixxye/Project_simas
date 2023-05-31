#include "../entities/Player.h"

namespace Entes
{
    namespace Characters
    {
        Player::Player(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        attack_body(size),
        is_attacking(false),
        Character(0, pos, velocity, size),
        attack_delay(0)
        {
            attack_body.setOrigin(size.x / 2, size.y / 2);
            life = 20;
            pPObserver = new Observers::PlayerObserver;
            pPObserver->set_player(this);
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
                exit(1);
            }
            move();
            attack_delay--;
        }

        void Player::move(char direction)
        {

            if (direction == 'R') //Right
            {
                vel.x += SPEED;
            }
            else if (direction == 'L') //Left
            {
                vel.x -= SPEED;
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
                vel.y += G;
            }
            else if (direction == 'U') //Up
            {
                vel.y -= 15.f;
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
            if (dmg)
            {
                life -= dmg;
                //substituir:
                //std::cout<<direction<<std::endl;
                if (direction == "Above")
                {
                    vel.y = 40 * SPEED;
                    other->set_vel(sf::Vector2f(other->get_vel().x, -5 * SPEED));
                }
                else if (direction == "Below")
                {
                    grounded = true;
                    move('U');
                    
                    other->set_vel(sf::Vector2f(other->get_vel().x, 5 * SPEED));
                }
                else if (direction == "Left")
                {
                    vel.x = -40 * SPEED;
                    other->set_vel(sf::Vector2f(-5 * SPEED, other->get_vel().y));
                }
                else if (direction == "Right")
                {
                    vel.x = 40 * SPEED;
                    other->set_vel(sf::Vector2f(5 * SPEED, other->get_vel().y));
                }
                std::cout<<life<<std::endl;
                move();
                //std::cout<<vel.x<<" "<<vel.y<<std::endl;
            }
        }

        void Player::attack()
        {
            //Pegar as teclas do player
            if (attack_delay <= 0)
            {
                attack_delay = ATTACK_DELAY;
                char direction = ' ';
                std::cout<<"Attacking"<<std::endl;
                is_attacking = true;

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                {
                    direction = 'U';
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    direction = 'L';
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    direction = 'R';
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                {
                    direction = 'D';
                }
                else 
                {
                    if (vel.x >= 0)
                        direction = 'R';
                    else 
                        direction = 'L';
                }
                if (direction == 'U')
                {
                    attack_body.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y - body.getSize().y));
                }
                else if (direction == 'R')
                {
                   attack_body.setPosition(sf::Vector2f(body.getPosition().x + body.getSize().x, body.getPosition().y)); 
                }
                if (direction == 'D')
                {
                    attack_body.setPosition(sf::Vector2f(body.getPosition().x, body.getPosition().y + body.getSize().y));
                }
                else if (direction == 'L')
                {
                   attack_body.setPosition(sf::Vector2f(body.getPosition().x - body.getSize().x, body.getPosition().y)); 
                }
                graphics_manager->draw(&attack_body);

                is_attacking = false;
            }
        }
    }
}
