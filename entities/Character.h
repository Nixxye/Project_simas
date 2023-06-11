#pragma once
#include "Entity.h"

namespace Entes
{
    namespace Characters
    {
        class Character : public Entity
        {
            protected:
                sf::RectangleShape body;
                bool alive;
                int life;
            public:
                Character(int index = -1, sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(50.f, 50.f), sf::Vector2f size = sf::Vector2f(0.f, 0.f));
                virtual ~Character();
                virtual void execute() = 0;
                virtual void save(std::ofstream& file) = 0;
                virtual void collide(Entity* other, std::string direction = "") = 0;
                void set_alive(bool a) { alive = a; }
                virtual void draw();
                void inflict_damage(int dmg) { life -= dmg; }
                sf::Vector2f get_position() { return body.getPosition(); }
                sf::Vector2f get_size() {return body.getSize();} 
                void set_position(sf::Vector2f pos) { body.setPosition(pos); }
                const bool get_alive() const { return alive; }
                const int get_life() const { return life; }
        };
    }
}