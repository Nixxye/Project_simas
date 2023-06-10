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
                body.setFillColor(sf::Color::Cyan);
            else
            {
                //texture = pGM->load_textures("../assets/plataform.png");
                texture = pGM->load_textures("../assets/obstacle3.png");
                body.setTexture(texture);
            }
            //checkpoint=false; 
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
                /*
                if (other->get_id() == 0)
                {
                    Entes::Characters::Player* player = static_cast<Entes::Characters::Player*>(other);
                    player->set_win(true);
                }
                */
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
        void Platform::execute()
        {
            move();
        }   
        void Platform::move()
        {
            vel.y += GRAVITY;
            if (grounded)
            {
                vel.y -= GRAVITY;
            }
            body.setPosition(body.getPosition() + vel);
        }
    }    
}

