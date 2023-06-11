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
    Ent();
    virtual ~Ent();

    virtual void draw() = 0;

    virtual void execute() = 0;
};

