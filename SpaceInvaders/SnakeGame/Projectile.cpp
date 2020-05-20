#include "Projectile.h"
#include "Constants.h"
void Projectile::Update(const std::vector<std::vector<Alien*>>& _aliensGrid) {
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

	if (getPosition().y < 0) {
		std::cout << "I WENT OFF THE SCREEN" << std::endl;
		m_shootable = true;
	}

	CheckCollisions(_aliensGrid);
}

void Projectile::CheckCollisions(const std::vector<std::vector<Alien*>>& _aliensGrid) {
	for (const auto& row : _aliensGrid) {
		for (auto alien : row) {
			auto* alienPointer = dynamic_cast<Alien*>(alien);
			if (alienPointer->GetAlive()) {
				if (CheckCollision(alien)) {
					alienPointer->SetAlive(false);
					m_shootable = true;
				}
			}
		}
	}

}
