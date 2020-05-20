#pragma once
#include "Entity.h"
class Alien final : public Entity {
public:
	explicit Alien(const std::string& _fileName) {
		LoadTexture(_fileName, 2);
		std::cout << "AMOUTN OF FRAMES" << m_textures.size();
		scale(0.5f, 0.5f);
	}

	void Update();

	void Render(sf::RenderWindow& _window);

	bool GetAlive() const { return m_alive; }
	
private:
	int m_currentFrame{ 0 };
	sf::Vector2f m_previousPosition;
	bool m_alive{ true };
};

