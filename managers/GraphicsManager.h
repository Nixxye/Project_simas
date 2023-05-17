#pragma once
//TODOTODOTODOTODOTODOTODOTODO
#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#define WIDTH 800
#define HEIGHT 600
#define FONT_PATH 
namespace Managers {
    class GraphicsManager
    {
    private:
        sf::RenderWindow* window;
        sf::View cam;
        std::map<const std::string, sf::Texture*> textures;
        sf::Font font;


        GraphicsManager();
        static GraphicsManager* instance;


    public:
        ~GraphicsManager();
        GraphicsManager* get_instance();
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