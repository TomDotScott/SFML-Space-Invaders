#pragma once
#include "Entity.h"

enum class EDirection {
	eUp, eDown, eLeft, eRight
};

enum class EType {
	eAlien, ePlayer
};

class Alien;

class Projectile final : public Entity {
public:
	explicit Projectile(const EDirection _direction, const EType _type) : m_direction(_direction), m_type(_type)
	{
		switch (m_type)
		{
		case EType::eAlien:
			LoadTexture("AlienProjectile_", 4);
			break;
		case EType::ePlayer:
			LoadTexture("PlayerProjectile.png");
			break;
		}
		setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
	}

	
	void Update();
	bool GetShootable() const { return m_shootable; }
	void SetShootable(const bool _shootable) { m_shootable = _shootable; }
	void RandomiseSprite();
private:
	void CheckCollisions(const std::vector<std::vector<Alien*>>& _aliensGrid);
	void CheckCollisions(Entity* _player);

	bool m_shootable{ true };
	EDirection m_direction;
	EType m_type;
};

