#pragma once

#include "GameObject.h"
#include "../observers/Observer.h"

namespace Entes
{
    class Entity : public GameObject
    {
        protected:
            //era const
            const int id;
            static int count;
            int damage;

            sf::RectangleShape body;
            static int speed;
            sf::Vector2f position;
            sf::Vector2f vel;
            static sf::Vector2f player_position;
            int lives;
            bool grounded;
            bool alive;

        public:
            Entity(int index = -1, sf::Vector2f pos = sf::Vector2f(0.f, 0.f), sf::Vector2f velocity = sf::Vector2f(0.f, 0.f), sf::Vector2f size = sf::Vector2f(50.f, 50.f));
            virtual ~Entity();

            virtual void draw();
            virtual void run() = 0;
            virtual void move(char direction = ' '){};
            //Função pode mudar.
            virtual void collide(Entity* other) = 0;

            void set_position(sf::Vector2f pos){body.setPosition(pos);}
            void set_grounded(bool g){grounded = g;}
            void set_alive(bool a){alive = a;}
            void set_vel(sf::Vector2f v){vel = v;}

            sf::Vector2f get_vel(){return vel;}
            int get_speed(){return speed;}
            sf::Vector2f get_position(){return body.getPosition();}
            sf::Vector2f get_size(){return body.getSize();} 
            const int get_id() const {return id;}
            const bool get_alive() const {return alive;}

            virtual Observers::Observer* get_observer() {return nullptr;}     
    };
}