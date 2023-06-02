#include "../entities/Enemy.h"
#include <math.h>
namespace Entes
{
    namespace Characters
    {
        Enemy::Enemy(int index, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Character(index, pos, velocity, size)
        {
            //texture = graphics_manager->load_textures("../entities/enemy.png");
            //body.setTexture(texture);
            
            //body.setFillColor(sf::Color::Magenta);
            //body.setPosition(300.f, 300.f);
        }

        Enemy::~Enemy()
        {
        }
        void Enemy::run()
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


