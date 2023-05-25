#include "GraphicsManager.h"

namespace Managers
 {

    GraphicsManager* GraphicsManager::instance = nullptr;


    GraphicsManager* GraphicsManager::get_instance() 
    {
        if (instance == nullptr) 
        {
            instance = new GraphicsManager();
        }
        return instance;
    }

    GraphicsManager::GraphicsManager():
    window( new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Jogo")),
    cam (sf::Vector2f(WIDTH / 2, HEIGHT / 2), sf::Vector2f(WIDTH, HEIGHT)),//centro e tamanho
    textures()
    {
        window->setFramerateLimit(60);
       //font->loadFromFile(FONT_PATH);
    }
    GraphicsManager::~GraphicsManager()
    {
        for (std::map<const std::string, sf::Texture*>::iterator it = textures.begin();it != textures.end();it++)
            delete it->second;
        textures.clear();
        delete window;
    }
    void GraphicsManager:: show ()
    {
        if (window_open())
            window->display();
    }
    void GraphicsManager:: clean ()
    {
        if (window_open())
            window->clear();
    }
    void GraphicsManager:: draw (sf::RectangleShape* body)
    {
        window->draw(*body);
    }
    sf::Texture* GraphicsManager:: load_textures (std::string path)
    {
        std::map<const std::string, sf::Texture*> :: iterator it = textures.find(path);
        if (it != textures.end())
            return it->second;

        sf::Texture* tex = new sf::Texture();

        tex->loadFromFile(path);
        
        textures[path] = tex;

        return tex;
    }
    //Se sobrar tempo, arrumar as interações da câmera com os cantos da fase.
    void GraphicsManager:: center (sf::Vector2f position1)
    {
        cam.setCenter (position1); 
        window->setView(cam);

    }
    void GraphicsManager:: center(sf::Vector2f position1, sf::Vector2f position2 )
    {
        cam.setCenter((position1.x+position2.x)/2,(position1.y+position2.y)/2);
        //if (position1.x)
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
    bool GraphicsManager:: window_open ()
    {
        return (window->isOpen());
    }

    sf::Font*  GraphicsManager:: get_font () const
    {
        return font;
    }
}