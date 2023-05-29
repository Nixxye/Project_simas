#include "../menus/Button.h"

#include <iostream>
//Para testes;

namespace Menus
{
    Managers::GraphicsManager* Button::graphics_manager(Managers::GraphicsManager::get_instance());

    Button::Button(sf::Vector2f position):
    body(sf::Vector2f(SIZEX, SIZEY)),
    text()
    {
        body.setOrigin(SIZEX / 2, SIZEY / 2);
        text.setOrigin(SIZEX / 2, SIZEY / 2);

        body.setFillColor(sf::Color::White);

        //sf::Font* font = graphics_manager->get_font();
        //text.setFont(*font);
        //text.setCharacterSize(100);
        text.setFillColor(sf::Color::Green);

        body.setPosition(position);
        text.setPosition(position);
    }
    Button::~Button()
    {

    }
    void Button::draw()
    {
        graphics_manager->draw(&body);
        graphics_manager->draw(&text);
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