#include "../entities/Ent.h"

int Ent::count(0);
//int Ent::speed(0);
Managers::GraphicsManager* Ent::pGM = Managers::GraphicsManager::get_instance();

Ent::Ent(sf::Vector2f size, sf::Vector2f pos):
id(count++),
body(size),
position(pos)
{

}


Ent::~Ent()
{
}

