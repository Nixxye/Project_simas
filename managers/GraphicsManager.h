#pragma once

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>

#define WIDTH 800
#define HEIGHT 600
//Linux:
#define FONT_PATH "../assets/PressStart2P-Regular.ttf"
//#define FONT_PATH "assets/PressStart2P-Regular.ttf"

namespace Managers 
{
    class GraphicsManager
    {
    private:
        sf::RenderWindow* window;
        sf::View cam;
        std::map<const std::string, sf::Texture*> textures;
        sf::Font* font;

        GraphicsManager();
        static GraphicsManager* instance;
    public:
        ~GraphicsManager();
        static GraphicsManager* get_instance();
        void show();
        void clean();
        void draw(sf::RectangleShape* body);
        void draw(sf::Text* text);
        sf::Texture* load_textures(std::string path);
        
        void center(sf::Vector2f position1);
        void center(sf::Vector2f position1, sf::Vector2f position2 );
        void reset_camera();
        sf::RenderWindow* get_window() const;
        void close_window ();
        bool window_open();
        sf::Font* get_font() const;
    };
}