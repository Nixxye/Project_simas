#include "../entities/Spike.h"

namespace Entes
{
    namespace Obstacles
    {
        Spike:: Spike(sf::Vector2f pos, int dmg):
        Obstacle(13, pos),
        damage(dmg)
        {
            texture = pGM->load_textures("../assets/spike.png");
            body.setTexture(texture);
        }
        Spike:: ~Spike()
        {
            
        }
        void Spike::collide(Entity* other, std::string direction)
        {
            other->inflict_damage(damage);
        }
        void Spike::execute()
        {
            move();
        }
        void Spike::move()
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

