#pragma once
#include "GameObject.h"
namespace entes
{
    class Entity : public GameObject
    {
        protected:
            static sf::Vector2f player_position;
            sf::Vector2f vel;
            bool grounded;
            
             
        public:
            Entity();
            ~Entity();
            void set_grounded(bool g){grounded = g;}
            sf::Vector2f get_vel(){return vel;}
            void set_vel(sf::Vector2f v){vel = v;}



        

  
        
    };
}