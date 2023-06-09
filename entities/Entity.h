#pragma once

#include "Ent.h"
#include "../observers/Observer.h"

#include <fstream>

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

            //sf::RectangleShape body;
            //Era int:
            static float speed;
            //sf::Vector2f position;
            sf::Vector2f vel;
            static sf::Vector2f player_position;
            //int life;
            bool grounded;
            //bool alive;
            float mass;
            int slowed;
            Managers::ColisionManager* colision_manager;

        public:
            Entity(int index = -1, sf::Vector2f velocity = sf::Vector2f(0.f, 0.f));
            virtual ~Entity();
            virtual void draw() = 0;
            virtual void execute() = 0;
            virtual void save(std::ofstream& file) = 0;
            virtual void move(char direction = ' '){};
            //Função pode mudar.
            virtual void collide(Entity* other, std::string  direction = "") = 0;
            virtual void inflict_damage(int dmg) { }

            virtual void set_position(sf::Vector2f pos) = 0;
            void set_grounded(bool g){grounded = g;}
            //virtual void set_alive(bool a){alive = a;}
            void set_vel(sf::Vector2f v){vel = v;}
            void set_colision_manager(Managers::ColisionManager* cm) { colision_manager = cm; }
            virtual void set_slowed(int s) { slowed = s; }
            virtual void set_alive(bool a) = 0;

            sf::Vector2f get_vel(){return vel;}
            int get_speed(){return speed;}
            virtual sf::Vector2f get_position()= 0;
            virtual sf::Vector2f get_size()= 0;
            const int get_id() const {return id;}
            //P/ gerenciador de colisões:
            virtual const bool get_alive() const { return true; }
            //virtual const int get_damage() const {return 0;}
            const float get_mass() const {return mass;}

            virtual Observers::Observer* get_observer() {return nullptr;}     

            //virtual void save(std::string filename) = 0;
    };
}