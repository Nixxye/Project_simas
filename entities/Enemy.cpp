#include "../entities/Enemy.h"
#include <math.h>

Enemy::Enemy(sf::Vector2f pos, sf::Vector2f size):
Character(pos, size),
alive(true)
{
    body.setFillColor(sf::Color::Magenta);
    body.setPosition(300.f, 300.f);
}

Enemy::~Enemy()
{
}

void Enemy::move()
{
    if (speed)
    {
        if (player_position.x > position.x)
        {
            if (vel.x < 3.f)
                vel.x += SPEED / 3;
        }
        else if (player_position.x < position.x)
        {
            if (vel.x > -3.f)
                vel.x -= SPEED / 3;
        }
        if (player_position.y > position.y)
        {
            if (vel.y < 3.f)
                vel.y += SPEED / 3;
        }
        else if (player_position.y < position.y)
        {
            if (vel.x > -3.f)
                vel.y -= SPEED / 3;
        }
        //NELSON
        vel +=  sf::Vector2f(((float) (rand()%20))/1000 - SPEED/20, ((float) (rand()%20))/1000 - SPEED/20);

        position+=sf::Vector2f(speed*vel.x, speed*vel.y);
        body.setPosition(position);
    }

}
