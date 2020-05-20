#pragma once
#include "Alien.h"
#include "Entity.h"
enum class EDirection {
	eUp, eDown, eLeft, eRight
};

class Projectile final : public Entity {
public:
	explicit Projectile(EDirection _direction) : m_direction(_direction)
	{
		LoadTexture("PlayerProjectile.png");
		setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	}
	void Update(const std::vector<std::vector<Alien*>>& _aliensGrid);
	bool GetShootable() const { return m_shootable; }
	void SetShootable(bool _shootable) { m_shootable = _shootable; }
private:
	void CheckCollisions(const std::vector<std::vector<Alien*>>& _aliensGrid);
	bool m_shootable{ true };
	EDirection m_direction;
};

