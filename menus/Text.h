#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "../managers/GraphicsManager.h"

namespace Menus
{
    class Text
    {
    private:
        sf::Text text;
        static Managers::GraphicsManager* pGM;
    public:
        Text(std::string n = " ");
        ~Text();

        void setPosition(sf::Vector2f pos);
        void setSize(int t);
        void setName(std::string n);
        void draw();
        void set_color(int c);
    };
}