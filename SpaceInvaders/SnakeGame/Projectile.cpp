#include "Projectile.h"
#include "Constants.h"
void Projectile::Update() {
	switch (m_direction) {
	case EDirection::eUp:
		m_velocity = { 0, -1 };
		break;
	case EDirection::eDown:
		m_velocity = { 0, 1 };
		break;
	}

	if (!m_shootable) {
		Entity::Update({ 1, 0.5f });
	}

	if(getPosition().y < 0)
	{
		std::cout << "I WENT OFF THE SCREEN" << std::endl;
		m_shootable = true;
	}
}
