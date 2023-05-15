#pragma once
//TODOTODOTODOTODOTODOTODOTODO
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#define WIDTH 800
#define HEIGHT 600
namespace Managers {
    class GraphicsManager
    {
    private:
        sf::RenderWindow* window;
        sf::View cam;
        std::map<const std::string, sf::Texture*> textures;
        sf::Font font;

    public:
        GraphicsManager();
        ~GraphicsManager();
        void show();
        void clean();
        void draw(sf::RectangleShape* body);
        sf::Texture* load_textures(std::string path);
        void center(sf::Vector2f position);
        void center(sf::Vector2f position1, sf::Vector2f position2 );
        sf::RenderWindow* get_window() const;
        void close_window ();
        bool window_open();
        sf::Font get_font() const;



    };
}