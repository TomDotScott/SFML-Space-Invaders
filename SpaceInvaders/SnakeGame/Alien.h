#pragma once
#include "Entity.h"
class Alien final : public Entity {
public:
	explicit Alien(const std::string& _fileName) {
		setOrigin(getGlobalBounds().width / 2, getGlobalBounds().height / 2);
		LoadTexture(_fileName, 2);
		scale(0.5f, 0.5f);
	}

	void Update();

	void Render(sf::RenderWindow& _window);

	void SetAlive(const bool _status) { m_alive = _status; }
	bool GetAlive() const { return m_alive; }
	
private:
	int m_currentFrame{ 0 };
	sf::Vector2f m_previousPosition;
	bool m_alive{ true };
};

