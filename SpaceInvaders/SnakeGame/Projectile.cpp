#include "Projectile.h"

#include "Alien.h"
#include "Constants.h"
#include "Game.h"

void Projectile::Update() {
	if (m_direction == EDirection::eUp) {
		m_velocity = { 0, -1 };
	}else{
		m_velocity = { 0, 1 };
	}

	if (!m_shootable) {
		Entity::Update({ 1, 0.5f });
	}

	if (m_type == EType::ePlayer) {
		CheckCollisions(Game::Instance().GetGrid());
		if (getPosition().y < 0) {
			m_shootable = true;
		}
	}else
	{
		CheckCollision(Game::Instance().GetPlayer());
		if (getPosition().y > constants::k_screenHeight) {
			m_shootable = true;
		}
	}
}

void Projectile::RandomiseSprite()
{
	setTexture(m_textures[rand() % m_textures.size()]);
}

void Projectile::CheckCollisions(const std::vector<std::vector<Alien*>>& _aliensGrid) {
	for (const auto& row : _aliensGrid) {
		for (auto alien : row) {
			if (alien->GetAlive()) {
				if (CheckCollision(alien)) {
					alien->Kill(false);
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
