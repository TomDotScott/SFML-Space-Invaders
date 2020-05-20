#include "Entity.h"

void Entity::Update(sf::Vector2f _velocityMultiplier)
{
	move({m_velocity.x * _velocityMultiplier.x, m_velocity.y * _velocityMultiplier.y});
}

bool Entity::CheckCollision(Entity* _collision) const
{
	return getGlobalBounds().intersects(_collision->getGlobalBounds());
}
