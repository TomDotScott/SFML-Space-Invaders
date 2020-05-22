#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"

class Entity : public sf::Sprite {
public:
	void LoadTexture(const std::string& _fileName) {
		if (m_texture.loadFromFile("Resources/Graphics/" + _fileName)) {
			setTexture(m_texture);
		}
	};

	void LoadTexture(const std::string& _fileName, const int _amountOfFrames) {
		m_totalFrames = _amountOfFrames;
		for (int i = 0; i < _amountOfFrames; i++) {
			sf::Texture texture;
			if (texture.loadFromFile("Resources/Graphics/" + _fileName + std::to_string(i) + ".png")) {
				m_textures.push_back(texture);
			}
		}
		setTexture(m_textures[0]);
	};

	void Update(sf::Vector2f _velocityMultiplier);

	bool CheckCollision(Entity* _collision) const;

protected:
	sf::Vector2f m_velocity;
	std::vector<sf::Texture> m_textures;
	int m_totalFrames{0};
	
private:
	sf::Texture m_texture;


};

