#include "../entities/Player.h"

#include "../managers/ColisionManager.h"

namespace Entes
{
    namespace Characters
    {
        Player::Player(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        attack_body(sf::Vector2f(size.x * 2, size.y * 2)),
        is_attacking(false),
        Character(0, pos, velocity, size),
        attack_delay(0)
        {
            attack_body.setOrigin(attack_body.getSize().x / 2, attack_body.getSize().y / 2);
            life = 20;
            damage = 3;
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
                //exit(1);
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
                //life -= dmg;
                //substituir:
                //std::cout<<direction<<std::endl;
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
                    
                    other->set_vel(sf::Vector2f(other->get_vel().x, 5 * SPEED));
                }
                else if (direction == "Left")
                {
                    life -= dmg;
                    vel.x = -40 * SPEED;
                    other->set_vel(sf::Vector2f(-5 * SPEED, other->get_vel().y));
                }
                else if (direction == "Right")
                {
                    life -= dmg;
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
                graphics_manager->draw(&attack_body);

                colision_manager->collide_attack(this, direction);
                //Por enquanto is_attacking é inútil:
                is_attacking = false;
            }
        }
    }
}
