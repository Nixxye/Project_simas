#include "../entities/Hud.h"

namespace Entes
{
    Hud* Hud::instance = nullptr; 
    Hud::Hud()
    {

    }
    Hud::~Hud()
    {
        
    }
    Hud* Hud::get_instance()
    {
        if(!instance)
            instance = new Hud();
        return instance;
    }
}