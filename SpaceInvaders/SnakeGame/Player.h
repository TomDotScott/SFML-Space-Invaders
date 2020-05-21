#pragma once
#include <iostream>


#include "Alien.h"
#include "Entity.h"
#include "Projectile.h"

class Player final : public Entity {
public:
	explicit Player(const std::string& _fileName)
	{
		m_projectile = new Projectile(EDirection::eUp, EType::ePlayer);
		LoadTexture(_fileName);
		scale(0.5, 0.5);
		m_projectile->scale(0.5, 0.5);
	};
	void Update(const std::vector<std::vector<Entity*>>& _aliensGrid);
	void Render(sf::RenderWindow& _window) const;

	Entity* GetProjectile() const { return m_projectile; }
private:
	bool m_canShoot{ true };
	Projectile* m_projectile;
	void Shoot();
};

