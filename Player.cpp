#include "Player.h"

Player::Player():
Entity(),
vel(0.f, 0.f)
{

}

Player::~Player()
{
}

void Player::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (vel.y >= - VEL_MAX)
            vel.y -= SPEED;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (vel.y <= VEL_MAX)
            vel.y += SPEED;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (vel.y >= - VEL_MAX)
        vel.x += SPEED;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        vel.x -= SPEED;
    }
    position += vel;
    body.setPosition(position);
    speed = (int) sqrt(vel.x*vel.x + vel.y*vel.y);
}