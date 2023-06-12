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
            const int id;
            static int count;

            static float speed;
            sf::Vector2f vel;
            static sf::Vector2f player_position;
            bool grounded;
            float mass;
            int slowed;
            Managers::ColisionManager* colision_manager;

        public:
            Entity(int index = -1, sf::Vector2f velocity = sf::Vector2f(0.f, 0.f));
            virtual ~Entity();
            virtual void draw() = 0;
            virtual void execute() = 0;
            virtual void save(std::ofstream& file) = 0;
            virtual void move(char direction = ' '){ vel.y += GRAVITY;};

            virtual void collide(Entity* other, std::string  direction = "") = 0;
            virtual void inflict_damage(int dmg) = 0;

            virtual void set_position(sf::Vector2f pos) = 0;
            void set_grounded(bool g){grounded = g;}

            void set_vel(sf::Vector2f v){vel = v;}
            void set_colision_manager(Managers::ColisionManager* cm) { colision_manager = cm; }
            virtual void set_slowed(int s) { slowed = s; }
            virtual void set_alive(bool a) = 0;

            sf::Vector2f get_vel(){return vel;}
            int get_speed(){return speed;}
            virtual sf::Vector2f get_position()= 0;
            virtual sf::Vector2f get_size()= 0;
            const int get_id() const {return id;}

            virtual const bool get_alive() const { return true; }

            const float get_mass() const {return mass;}
    };
}