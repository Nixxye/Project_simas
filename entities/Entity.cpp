#include "Entity.h"
using namespace entes;

sf::Vector2f Entity::player_position(200.f, 200.f);


Entity::Entity():
GameObject(),
vel(0.f, 0.f),
grounded(false)

{

}
Entity::~Entity()
{

}