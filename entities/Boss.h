#pragma once

#include "../entities/Enemy.h"
#include "../lists/EntityList.h"
#include "../entities/Bullet.h"

//TODO: Fazer a função move de enemy ser virtual e enemy 1 receber a função atual;
namespace Entes
{
    namespace Characters
    {
        class Boss: public Enemy
        {
        private:
            //Podemos fazer balas com propridedades diferentes se der tempo:
            Lists::EntityList bullets;
            int attack_delay;
        public:
            Boss(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
            ~Boss();

            void execute();
            void move();
            void attack();
            void draw();
            void save(std::ofstream& file);

            void collide(Entity* other, std::string direction = "");
            void collide_bullets();
            
            Lists::List<Entes::Entity>::Iterator<Entes::Entity> get_bullets() { return bullets.get_first(); }
            void add_bullet(Entes::Entity* bullet);
            const int get_n_bullets() const { return bullets.get_size(); }
        };
    }
}
