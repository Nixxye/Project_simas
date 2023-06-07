#include "../entities/Bullet.h"
#include "../managers/ColisionManager.h"

namespace Entes
{
    Bullet::Bullet(sf::Vector2f pos, sf::Vector2f velocity, float time):
    Entity(4, velocity),
    lifetime(time), 
    body(10),
    friendly(false),
    damage(0.5),
    alive(true)
    {
        body.setPosition(pos);
        texture = pGM->load_textures("../assets/bullet.png");
        body.setTexture(texture);
    }
    Bullet::~Bullet()
    {

    }
    void Bullet::execute()
    {
        if (alive)
        {
            move();
            //std::cout<<"Moveu"<<std::endl;
            lifetime--;
            if (lifetime <= 0)
                alive = false;
        }
        
    }
    void Bullet::set_alive(bool a)
    {
        lifetime = TIME;
        alive = a;
    }
    void Bullet::draw()
    {
        pGM->draw(&body);
    }
    void Bullet::move()
    {
        if (alive)
        {
            if (!grounded)
                vel.y += G;
            if (speed > 0.f)
                body.setPosition(body.getPosition() + sf::Vector2f(vel.x * speed, vel.y * speed));    
        }
    }
    void Bullet::call_colision()
    {
        colision_manager->collide_bullets(this);
    }
    void Bullet::collide(Entity* other, std::string direction)
    {
        int index = other->get_id();
        lifetime -= 5;
        switch (index)
        {
            //Player:
        case 0:
            //Isso vai para o gerenciador de colisões:
            colision_manager->elastic_colision(this, other);
            //std::cout<<"Here"<<std::endl;
            if (static_cast<Entes::Characters::Player*>(other)->get_damage() > 0 && !friendly)
            {
                friendly = true;
                body.setFillColor(sf::Color::Magenta);
            }
            //if (!friendly)
                //other->inflict_damage(damage);
            break;
            //Boss:
        case 3:
            if (friendly)
            {
                colision_manager->elastic_colision(this, other);
                alive = false;
                other->inflict_damage(damage);
            }
        case 11:
            if (direction == "Right" || direction == "Left")
            {
                vel = sf::Vector2f(- CR*vel.x, vel.y);
            }
            else 
            {
                vel = sf::Vector2f(vel.x, - CR*vel.y);
            }
        default:
            break;
        }
        move();
    }
    void Bullet::save(std::ofstream& file)
    {
        if (!file.is_open())
        {
            std::cout<<"Error: Cannot open enemy file!"<<std::endl;
            return;
        }
        file<<id<<std::endl;
        if (alive)
            file<<1<<std::endl;
        else
            file<<0<<std::endl;
        file<<damage<<std::endl
        <<body.getPosition().x<<std::endl<<body.getPosition().y<<std::endl
        <<vel.x<<std::endl<<vel.y<<std::endl
        <<body.getRadius()<<std::endl
        <<lifetime<<std::endl<<damage<<std::endl;  
        if (friendly)
            file<<1<<std::endl<<std::endl;
        else
            file<<0<<std::endl<<std::endl; 
    }
}
