#include "../menus/Button.h"

#include <iostream>

namespace Menus
{
    Managers::GraphicsManager* Button::pGM(Managers::GraphicsManager::get_instance());

    Button::Button(sf::Vector2f position):
    body(sf::Vector2f(SIZEX, SIZEY)),
    text()
    {
        body.setOrigin(SIZEX / 2, SIZEY / 2);
        text.setOrigin(SIZEX / 2 - 50, SIZEY / 2 - 25);

        body.setFillColor(sf::Color(240,230,140));
        body.setOutlineThickness(6);
        body.setOutlineColor(sf::Color::Black);

        text.setFont(*pGM->get_font());
        text.setFillColor(sf::Color(65, 130, 190));
        text.setCharacterSize(50);

        body.setPosition(position);
        text.setPosition(position);
        text.setOutlineThickness(3.f);
        text.setOutlineColor(sf::Color:: Black);
    }
    Button::~Button()
    {

    }
    void Button::draw()
    {
        pGM->draw(&body);
        pGM->draw(&text);
    }
    void Button::change_color()
    {
        if (body.getFillColor() == sf::Color(240,230,140))
            body.setFillColor(sf::Color(205,92,92));
        else
            body.setFillColor(sf::Color(240,230,140));
    }
    void Button::set_name(std::string name)
    {
        text.setString(name);
    }
    void Button :: set_position(sf::Vector2f position)
    {
        body.setPosition(position);
        text.setPosition(position);
    }
}