#pragma once

#include "../entities/Entity.h"
#include <SFML/Graphics.hpp>
#include <fstream>

#define LIFETIME 1000

namespace Entes
{
    class Bullet: public Entity
    {
        private:
            int lifetime;
            sf::CircleShape body;
            bool friendly;
            int damage;
            bool alive;
        public:
            Bullet(sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), float time = 100.f);
            Bullet(bool alv, sf::Vector2f pos, sf::Vector2f velocity, float dmg, float radius, float lftm, bool frndl);
            ~Bullet();
            
            void execute();
            void move();
            void draw();
            void collide(Entity* other, std::string direction = "");
            void call_colision();
            sf::Vector2f get_position() { return body.getPosition(); }
            void inflict_damage(int dmg) { lifetime -= dmg; }
            void set_alive(bool a);
            sf::Vector2f get_size() {return sf::Vector2f(body.getRadius()*2, body.getRadius()*2); } 
            void set_position(sf::Vector2f pos) { body.setPosition(pos); }
            void set_friendly(bool f){friendly = f;}
            float get_lifetime() { return lifetime; }
            const bool get_friendly() const { return friendly; }
            void set_fill_color (sf::Color c) { body.setFillColor(c); }
            const int get_damage() const { return damage; }
            const bool get_alive() const { return alive; }
            void save(std::ofstream& file);
    };  
}
