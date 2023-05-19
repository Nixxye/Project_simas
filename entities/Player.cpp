#include "../entities/Player.h"

#include <iostream>

namespace characters
{
    Player::Player(sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
    Character(pos, velocity, size)
    {
        lives = 3;
    }

    Player::~Player()
    {
    }
    void Player::run()
    {
        move();
    }

    void Player::move()
    {
        if (direction == 'R') //Right
        {
            vel.x += SPEED;
        }
        if (direction == 'L') //Left
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
            vel.y -= 10.f;
        }

        body.setPosition(body.getPosition() + vel);
        player_position = body.getPosition();
        speed = (int) sqrt(vel.x*vel.x + vel.y*vel.y);
    }
}
