#pragma once
#include "Entity.h"

//vai ser 50.0
#define OBSTACLE_SIZE 75.0

namespace Entes
{
    namespace Obstacles
    {
        class Obstacle: public Entity
        {
            protected:
                sf::RectangleShape body;
                bool exists;
            public:
                Obstacle(int index = -1, sf::Vector2f pos = sf::Vector2f(100.f, 600.f));
                ~Obstacle();
                virtual void execute() = 0;
                virtual void move();
                void draw();
                virtual void collide(Entes::Entity* other, std::string  direction = "") = 0;
                //Vai ser virtual pura;
                virtual void save(std::ofstream& file) {}
                void set_alive(bool a) { exists = a; }
                const bool get_alive() const { return exists; }
                sf::Vector2f get_position() { return body.getPosition(); }
                sf::Vector2f get_size() { return body.getSize();} 
                void set_position(sf::Vector2f pos) { body.setPosition(pos); }
                //Não criamos nenhuma plataforma capaz de receber dano:
                void inflict_damage(int dmg){}
        };    
    }
}

