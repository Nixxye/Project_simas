#include "../entities/Enemy.h"
#include <math.h>
namespace Entes
{
    namespace Characters
    {
        Enemy::Enemy(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Character(pos, velocity, size)
        {
            texture = pGM->load_textures("../assets/enemy1.png");
            body.setTexture(texture);
            
            //body.setFillColor(sf::Color::Magenta);
            //body.setPosition(300.f, 300.f);
        }

        Enemy::~Enemy()
        {
        }
        void Enemy::execute()
        {
            move();
        }
        void Enemy::move()
        {
            if (speed > 0.f)
            {
                if (player_position.x > position.x)
                {
                    if (vel.x < 3.f)
                        vel.x += SPEED / 10.f;
                }
                else if (player_position.x < position.x)
                {
                    if (vel.x > -3.f)
                        vel.x -= SPEED / 10.f;
                }
                if (player_position.y > position.y)
                {
                    if (vel.y < 3.f)
                        vel.y += SPEED / 10.f;
                }
                else if (player_position.y < position.y)
                {
                    if (vel.y > -3.f)
                        vel.y -= SPEED / 10.f;
                }

                //vel += sf::Vector2f(((float) (rand()%20))/1000 - SPEED/30, ((float) (rand()%20))/1000 - SPEED/30);
                position+=sf::Vector2f(speed*vel.x, speed*vel.y);
                body.setPosition(position);
            }

        }
    }
}


