#pragma once

#include "Ent.h"
#include "../observers/Observer.h"

namespace Managers
{
    class ColisionManager;
}

namespace Entes
{
    class Entity : public Ent
    {
        protected:
            //era const
            const int id;
            static int count;
            int damage;

            //sf::RectangleShape body;
            static int speed;
            //sf::Vector2f position;
            sf::Vector2f vel;
            static sf::Vector2f player_position;
            int life;
            bool grounded;
            bool alive;
            float mass;
            Managers::ColisionManager* colision_manager;

        public:
            Entity(int index = -1, sf::Vector2f velocity = sf::Vector2f(0.f, 0.f));
            virtual ~Entity();
            virtual void draw();
            virtual void run() = 0;
            virtual void move(char direction = ' '){};
            //Função pode mudar.
            virtual void collide(Entity* other, std::string  direction = "") = 0;

            virtual void set_position(sf::Vector2f pos) = 0;
            void set_grounded(bool g){grounded = g;}
            virtual void set_alive(bool a){alive = a;}
            void set_vel(sf::Vector2f v){vel = v;}
            void set_colision_manager(Managers::ColisionManager* cm) { colision_manager = cm; }

            sf::Vector2f get_vel(){return vel;}
            int get_speed(){return speed;}
            virtual sf::Vector2f get_position()= 0;
            virtual sf::Vector2f get_size()= 0;
            const int get_id() const {return id;}
            const bool get_alive() const {return alive;}
            const int get_damage() const {return damage;}
            const float get_mass() const {return mass;}

            virtual Observers::Observer* get_observer() {return nullptr;}     
    };
}