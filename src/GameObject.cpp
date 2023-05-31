#include "../entities/GameObject.h"

int Ent::count(0);
int Ent::speed(0);
Managers::GraphicsManager* Ent::pGM = Managers::GraphicsManager::get_instance();

Ent::Ent():
id(count++),
body(sf::Vector2f(50.f, 50.f)),
position(200.f, 200.f)
{

}


Ent::~Ent()
{
}

