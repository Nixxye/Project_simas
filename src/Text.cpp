#include "../menus/Text.h"

namespace Menus
{
    Managers::GraphicsManager* Text::pGM(Managers::GraphicsManager::get_instance());

    Text::Text(std::string n)
    {
        text.setString(n);
        text.setFont(*pGM->get_font());
        text.setCharacterSize(30);
        text.setPosition(sf::Vector2f(100.f, 25.f));
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
}