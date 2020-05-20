#include "Entity.h"

void Entity::Update(float _velocityMultiplier)
{
	move({m_velocity.x * _velocityMultiplier, m_velocity.y});
}

bool Entity::CheckCollision(Entity* _collision) const
{
	return getGlobalBounds().intersects(_collision->getGlobalBounds());
}
