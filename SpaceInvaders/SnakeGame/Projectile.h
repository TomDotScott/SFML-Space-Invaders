#pragma once
#include "Entity.h"
enum class EDirection {
	eUp, eDown, eLeft, eRight
};

class Projectile final : public Entity {
public:
	explicit Projectile(EDirection _direction) : m_direction(_direction) { LoadTexture("PlayerProjectile.png"); }
	void Update();
	bool GetShootable() const { return m_shootable; }
	void SetShootable(bool _shootable) { m_shootable = _shootable; }
private:
	bool m_shootable{ true };
	EDirection m_direction;
};

