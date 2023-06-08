#include "../entities/Spike.h"

namespace Entes
{
    namespace Obstacles
    {
        Spike:: Spike(sf::Vector2f pos, int dmg):
        Obstacle(13, pos),
        damage(dmg)
        {
            body.setFillColor(sf::Color::Red);
            //texture = pGM->load_textures("../assets/obstacle1.png");
            //body.setTexture(texture);
            //std::cout<<"Espinho de id: "<<id<<"e dano "<<damage<<std::endl;
        }
        Spike:: ~Spike()
        {
            
        }
        void Spike::collide(Entity* other, std::string direction)
        {
            other->inflict_damage(damage);
            std::cout<<"Tome "<<id<<std::endl;
        }
    }    
}

