#include "../entities/Enemy.h"
#include <math.h>
namespace Entes
{
    namespace Characters
    {
        Enemy::Enemy(int index, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Character(index, pos, velocity, size),
        damage(0)
        {

        }

        Enemy::~Enemy()
        {
        }
        void Enemy::execute()
        {
            move();
            if (alive && life < 0)
                alive = false;
        }
        void Enemy::move()
        {

        }
    }
}


