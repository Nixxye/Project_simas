#include "../menus/Text.h"

namespace Menus
{
    Managers::GraphicsManager* Text::pGM(Managers::GraphicsManager::get_instance());

    Text::Text(std::string n)
    {
        text.setString(n);
        text.setFont(*pGM->get_font());
        text.setCharacterSize(30);
        text.setOrigin(15.f,15.f);
        text.setPosition(sf::Vector2f(100.f, 25.f));
        text.setFillColor(sf::Color:: White);
        text.setOutlineThickness(5.f);
        text.setOutlineColor(sf::Color:: Black);
    }
    Text::~Text()
    {
        
    }
    void Text::setPosition(sf::Vector2f pos)
    {
        text.setPosition(pos);
    }
    void Text::setSize(int t)
    {
        text.setCharacterSize(t);
    }
    void Text::setName(std::string n)
    {
        text.setString(n);
    }
    void Text::draw()
    {
        pGM->draw(&text);

    }
    void Text :: set_color (int c)
    {
        if (c == 0)
            text.setFillColor(sf::Color(255,165,0));
    }
}