#include "../entities/Enemy.h"
#include <math.h>
namespace Entes
{
    namespace Characters
    {
        //COLOCAR DAMAGE NA CONSTRUTORA NO FUTURO:
        Enemy::Enemy(int index, sf::Vector2f pos, sf::Vector2f velocity, sf::Vector2f size):
        Character(index, pos, velocity, size),
        damage(0)
        {
            //Teste:
            //texture = pGM->load_textures("../assets/enemy2.png");;
            //body.setTexture(texture);
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


