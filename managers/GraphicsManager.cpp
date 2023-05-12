#include "GraphicsManager.h"

namespace Managers {
    GraphicsManager::GraphicsManager():
    window( new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Jogo")),
    cam (sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),//centro e tamanho
    textures()
    {
       
    }
    GraphicsManager::~GraphicsManager()
    {

    }
    void GraphicsManager:: show ()
    {
        window->display();
    }
    void GraphicsManager:: clean ()
    {
        window->clear();
    }
    void GraphicsManager:: draw (sf::RectangleShape* body)
    {
        window->draw(*body);
    }
    sf::Texture* GraphicsManager:: load_textures (std::string path)
    {
        std::map<const std::string, sf::Texture*> :: iterator it = textures.find (path);;
        if (it != textures.end())
            return it->second;

        sf::Texture* tex = new sf::Texture();

        tex->loadFromFile(path);
        
        textures[path] = tex;

        return tex;
    }
    void GraphicsManager:: center (sf::Vector2f position)
    {
        cam.setCenter (position);
        window->setView(cam);
    }
    sf::RenderWindow* GraphicsManager:: get_window () const 
    {
        return window;
    }
    void GraphicsManager :: close_window ()
    {
         window->close();
    }
}