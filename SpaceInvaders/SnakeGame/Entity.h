#pragma once
#include <iostream>

#include "SFML/Graphics.hpp"

class Entity : public sf::Sprite {
public:
	void LoadTexture(const std::string& _fileName)
	{
		if (m_texture.loadFromFile("Resources/" + _fileName)) {
			std::cout << "Texture loaded";
			setTexture(m_texture);
		}
	};

	void Update(sf::Vector2f _velocityMultiplier);

	bool CheckCollision(Entity* _collision) const;

protected:
	sf::Vector2f m_velocity;

private:
	sf::Texture m_texture;


};

