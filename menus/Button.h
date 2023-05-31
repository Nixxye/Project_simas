#pragma once

#include <SFML/Graphics.hpp>

#include "../managers/GraphicsManager.h"

#define SIZEX 600.f
#define SIZEY 80.f

namespace Menus
{
    class Button
    {
    private:
        sf::RectangleShape body;
        sf::Text text;
        static Managers::GraphicsManager* pGM;
    public:
        Button(sf::Vector2f position = sf::Vector2f(0.f, 0.f));
        ~Button();  
        void draw();
        void change_color();
        void set_name(std::string name);
    };
}
