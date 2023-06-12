#pragma once 
#include "Enemy.h"

#define TIME_MOTION 200

namespace Entes
{
    namespace Characters
    {
        class Alarm: public Enemy
        {
        private:
            int motion_counter;
        public:
            Alarm(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
            Alarm(bool alv, int lf, sf::Vector2f pos, sf::Vector2f velocity, float dmg, sf::Vector2f size, float mc);
            ~Alarm();
            
            void collide(Entity* other, std::string direction = "");
            void move();
            void save(std::ofstream& file);
        };   
    } 
}

