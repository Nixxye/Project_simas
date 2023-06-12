#include "../entities/Slime.h"

#include <math.h>

namespace Entes
{
    namespace Obstacles
    {
        Slime:: Slime(sf::Vector2f pos, int sl):
        Obstacle(12, pos),
        slow_level(sl)
        {
            texture = pGM->load_textures("../assets/slime.png");
            body.setTexture(texture);
        }
        Slime:: ~Slime()
        {
            
        }   
        void Slime::collide(Entity* other, std::string  direction) 
        {
            other->set_slowed(slow_level);
        }
        void Slime::execute()
        {
            move();
        }
        void Slime::move()
        {
            vel.y += GRAVITY;
            if (grounded)
            {
                vel.y -=GRAVITY;
            }
            body.setPosition(body.getPosition() + vel);
        }
    }    
}

