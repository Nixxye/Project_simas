#include "../entities/Hud.h"

namespace Entes
{
    bool Hud::win(false);
    int Hud::points(0);  
     
    Hud::Hud(Lists::EntityList* p):
    kills(0),
    life(),
    position(),
    life_bars(),
    players(p),
    clock(0),
    time(" ")
    {   
        life.resize(2);
        life_bars.resize(2);
        position.resize(3);

        life_bars[0].setSize(sf::Vector2f(15.f * 20, 15.f));
        life_bars[1].setSize(sf::Vector2f(15.f * 20, 15.f));

        life_bars[0].setFillColor(sf::Color::Red);
        life_bars[1].setFillColor(sf::Color::Red);

        position[0] = sf::Vector2f(-350.f, -230.f);
        position[1] = sf::Vector2f(350.f, -230.f);
        position[2] = sf::Vector2f(-320.f, -270.f);

        //life_bars[1].setOrigin(sf::Vector2f(15.f * 20, 0.f));
        //life_bars[1].setPosition(sf::Vector2f(100.f, 100.f));
    }
    Hud::~Hud()
    {

    }
    void Hud::execute()
    {
        clock += (*players->get_first())->get_speed();
        update_life();
        draw();
    }
    void Hud::draw()
    {
        draw_bars();

        time.setPosition(position[2] + pGM->get_cameraPosition());
        time.setName(std::to_string((int) clock));
        time.draw();
    }
    void Hud::update_life()
    {
        Lists::List<Entes::Entity>::Iterator<Entes::Entity> it = players->get_first();
        for (int i = 0; it != nullptr && i < 2; i++, it++)
        {
            life[i] = static_cast<Entes::Characters::Character*>(*it)->get_life();
        }
    }
    void Hud::draw_bars()
    {
        life_bars[0].setSize(sf::Vector2f(15.f * life[0], 15.f));
        life_bars[0].setPosition(position[0] + pGM->get_cameraPosition());
        life_bars[1].setSize(sf::Vector2f(15.f * life[1], 15.f));
        life_bars[1].setPosition(position[1] + pGM->get_cameraPosition() - sf::Vector2f(life[1] * 15.f ,0.f));

        pGM->draw(&life_bars[0]);
        pGM->draw(&life_bars[1]);
    }
}