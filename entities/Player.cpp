#include "../entities/Player.h"
Player::Player(sf::Vector2f pos, sf::Vector2f size):
Character(pos, size)
{
    lives = 3;
}

Player::~Player()
{
}

void Player::move(char direction)
{
    if (direction == 'L') //Left
    {
        vel.x += SPEED;
    }
    if (direction == 'R') //Right
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
    //std::cout<<body.getPosition().x<<" "<<body.getPosition().y<<std::endl;
    //player_position += vel;
    body.setPosition(body.getPosition() + vel);
    speed = (int) sqrt(vel.x*vel.x + vel.y*vel.y);
}