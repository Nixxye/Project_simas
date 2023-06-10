#pragma once

#include <SFML/Graphics.hpp>
#include "../managers/GraphicsManager.h"

#define GRAVITY 0.3
#define SPEED 0.1
#define VEL_MAX 10.0

class Ent
{
protected:

    const int id;
    static Managers::GraphicsManager* pGM;
    sf :: Texture* texture;
public:
    Ent(sf::Vector2f size = sf::Vector2f(50.f, 50.f), sf::Vector2f pos = sf::Vector2f(0.f, 0.f));
    virtual ~Ent();

    virtual void draw() = 0;

    virtual void execute() = 0;
};

