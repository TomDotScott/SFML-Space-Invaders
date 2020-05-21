#include "Projectile.h"

#include "Alien.h"
#include "Constants.h"
void Projectile::Update(const std::vector<std::vector<Entity*>>& _aliensGrid, Entity* _player) {
	if (m_direction == EDirection::eUp) {
		m_velocity = { 0, -1 };
	}else{
		m_velocity = { 0, 1 };
	}

	if (!m_shootable) {
		Entity::Update({ 1, 0.5f });
	}

	if (getPosition().y < 0) {
		std::cout << "I WENT OFF THE SCREEN" << std::endl;
		m_shootable = true;
	}

	if (m_type == EType::ePlayer) {
		CheckCollisions(_aliensGrid);
	}else
	{
		CheckCollision(_player);
	}
}

void Projectile::RandomiseSprite()
{
	setTexture(m_textures[rand() % m_textures.size()]);
}

void Projectile::CheckCollisions(const std::vector<std::vector<Entity*>>& _aliensGrid) {
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

void Projectile::CheckCollisions(Entity* _player) {
	if(CheckCollision(_player))
	{
		//Kill the players
		std::cout << "I HIT THE PLAYER" << std::endl;
	}
}
