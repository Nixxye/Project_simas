#pragma once

#include "../entities/Entity.h"
#include <SFML/Graphics.hpp>


namespace Entes
{
    class Bullet: public Entity
    {
        private:
            float lifetime;
            sf::CircleShape body;
        public:
            Bullet(float vx = 0.f, float vy = 0.f, float time = 100.f);
            ~Bullet();
            void run();
            void move();
            void collide(Entity* other, std::string direction = ""){};
            sf::Vector2f get_position() { return body.getPosition(); }
            //Mudar isso dps;
            sf::Vector2f get_size() {return sf::Vector2(body.getRadius(), body.getRadius()); } 
            void set_position(sf::Vector2f pos) { body.setPosition(pos); }
    };  
}
