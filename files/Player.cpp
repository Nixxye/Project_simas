#include "../headers/Player.h"

Player::Player():
Entity()
{
    lives = 3;
}

Player::~Player()
{
}

void Player::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (vel.y >= - VEL_MAX)
        vel.x += SPEED;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
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
    player_position += vel;
    body.setPosition(player_position);
    speed = (int) sqrt(vel.x*vel.x + vel.y*vel.y);
}