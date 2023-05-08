#include "../entities/Obstacle.h"

Obstacle::Obstacle(sf::Vector2f pos, sf::Vector2f size):
Entity()
{
    body.setPosition(pos);
    body.setSize(size);
}
Obstacle::~Obstacle()
{
    
}
void Obstacle::move(){}