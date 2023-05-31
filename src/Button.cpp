#include "../menus/Button.h"

#include <iostream>
//Para testes;

namespace Menus
{
    Managers::GraphicsManager* Button::pGM(Managers::GraphicsManager::get_instance());

    Button::Button(sf::Vector2f position):
    body(sf::Vector2f(SIZEX, SIZEY)),
    text()
    {
        body.setOrigin(SIZEX / 2, SIZEY / 2);
        text.setOrigin(SIZEX / 2 - 50, SIZEY / 2 - 25);

        body.setFillColor(sf::Color::White);

        text.setFont(*pGM->get_font());
        text.setFillColor(sf::Color::Black);
        text.setCharacterSize(60);

        body.setPosition(position);
        text.setPosition(position);
    }
    Button::~Button()
    {

    }
    void Button::draw()
    {
        pGM->draw(&body);
        pGM->draw(&text);
        //std::cout<<"Printando"<<std::endl;
    }
    void Button::change_color()
    {
        if (body.getFillColor() == sf::Color::White)
            body.setFillColor(sf::Color::Red);
        else
            body.setFillColor(sf::Color::White);
    }
    void Button::set_name(std::string name)
    {
        text.setString(name);
    }
}