#pragma once
#include "Entity.h"
#include "Projectile.h"

class Alien final : public Entity {
public:
	explicit Alien(const std::string& _fileName) {
		setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
		LoadTexture(_fileName, 2);
		scale(0.5f, 0.5f);

		m_projectile = new Projectile(EDirection::eDown, EType::eAlien);
	}

	void Update();
	void Update(const std::vector<std::vector<Entity*>>& _grid, Entity* _player);

	void Animate();

	void Render(sf::RenderWindow& _window) const;

	void Shoot() const;
	
	void SetAlive(const bool _status) { m_alive = _status; }
	bool GetAlive() const { return m_alive; }
	bool GetCanShoot() const { return m_canShoot; }
	
private:
	int m_currentFrame{ 0 };
	sf::Vector2f m_previousPosition;
	bool m_alive{ true };
	Projectile* m_projectile;
	bool m_canShoot{ true };
};

