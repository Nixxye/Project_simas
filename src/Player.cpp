#include "../entities/Player.h"

namespace Entes
{
    namespace Characters
    {
        Player::Player(int index,sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Character(pos, velocity, size)
        {
            lives = 3;
            if (index == 1)
            {
                pPObserver = new Observers::PlayerObserver(1);
                texture = pGM->load_textures("../assets/player.png");
            }
            else if (index == 2)
            {
                pPObserver = new Observers::PlayerObserver(2);
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
        void Player::execute()
        { 
            if (lives < 0)
                alive = false;
            if (!alive)
            {
                
                //DAR UM JEITO DE FAZER UM GAME OVER DECENTE:
                std::cout<<"Faleceu"<<std::endl;
                //exit(1);
            }
            move();
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
                //body.setPosition(body.getPosition() + sf::Vector2f(0.f, 0.5));
            }
            //N sei pq a gravidade está mais rápida quando nos movemos; -> Gimmick
            if (direction == '0')
            {
                body.setPosition(body.getPosition() + vel);
                player_position = body.getPosition();
                speed = (int) sqrt(vel.x*vel.x + vel.y*vel.y);   
            }
        }
    }
}
