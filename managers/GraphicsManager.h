#pragma once
//TODOTODOTODOTODOTODOTODOTODO
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class GraphicsManager
{
private:
    sf::RenderWindow* window;
    sf::View cam;
    std::map<const std::string, sf::Texture*> textures;
public:
    GraphicsManager();
    ~GraphicsManager();
    void show() const;
    void clean();
    void draw();
    void load_textures();
    void center();
    sf::RenderWindow* get_window() const;
};