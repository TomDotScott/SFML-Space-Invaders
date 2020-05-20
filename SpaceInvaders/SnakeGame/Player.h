#pragma once
#include <iostream>

#include "Entity.h"
#include "Projectile.h"

class Player final : public Entity {
public:
	explicit Player(const std::string& _fileName) : m_projectile(EDirection::eUp)
	{
		LoadTexture(_fileName);
		scale(0.5, 0.5);
		m_projectile.scale(0.5, 0.5);
	};
	void Update();
	void Render(sf::RenderWindow& _window) const;
private:
	bool canShoot{ true };
	Projectile m_projectile;
	void Shoot();
};

