#include "../entities/GameObject.h"

int GameObject::count(0);
int GameObject::speed(0);
Managers::GraphicsManager* GameObject::graphics_manager = Managers::GraphicsManager::get_instance();

GameObject::GameObject():
id(count++),
body(sf::Vector2f(50.f, 50.f)),
position(200.f, 200.f)
{
}


GameObject::~GameObject()
{
}