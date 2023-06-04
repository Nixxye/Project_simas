#pragma once

#include "../entities/Entity.h"
#include <SFML/Graphics.hpp>

#define TIME 200

namespace Entes
{
    class Bullet: public Entity
    {
        private:
            float lifetime;
            sf::CircleShape body;
            bool friendly;
        public:
            Bullet(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), float time = 100.f);
            ~Bullet();
            void execute();
            void move();
            //N sei se precisa;
            void draw();
            void collide(Entity* other, std::string direction = "");
            void call_colision();
            sf::Vector2f get_position() { return body.getPosition(); }
            //Mudar isso dps;
            void set_alive(bool a);
            sf::Vector2f get_size() {return sf::Vector2f(body.getRadius()*2, body.getRadius()*2); } 
            void set_position(sf::Vector2f pos) { body.setPosition(pos); }
            void set_friendly(bool f){friendly = f;}
            float get_lifetime() { return lifetime; }
            const bool get_friendly() const { return friendly; }
            void set_fill_color (sf::Color c) { body.setFillColor(c); }
    };  
}
