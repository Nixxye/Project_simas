#include "../entities/Platform.h"
#include "../entities/Player.h"
#include "../entities/Enemy.h"
namespace Entes
{
    namespace Obstacles
    {
        Platform:: Platform(sf::Vector2f pos, bool check):
        Obstacle(11, pos)
        {
            checkpoint=check; 
            if (check)
            {
                texture = pGM->load_textures("../assets/final.png");
            }
            else
            {
                texture = pGM->load_textures("../assets/plataform.png");
            }
           body.setTexture(texture);
        }
        Platform:: ~Platform()
        {
            
        } 
        void Platform::collide(Entity* other, std::string  direction)
        {
            if (checkpoint)
            {
                /*Entes::Characters:: Enemy* e = dynamic_cast<Entes::Characters::Enemy*>(other);
                if (e != nullptr)
                {
                    return;
                }*/
                Entes::Characters:: Player* player = dynamic_cast<Entes::Characters::Player*>(other);
                if (player != nullptr)
                {
                    player->set_win(true);
                    //printf("Plataforma Player\n");
                }
                /*else
                {
                    //printf("Plataforma normal\n");
                }*/
            }
        }   
    }    
}

