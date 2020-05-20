#pragma once
#include "Entity.h"
class Alien : public Entity {
public:
	explicit Alien(const std::string& _fileName) {
		LoadTexture(_fileName);
		scale(0.5f, 0.5f);
	}

	void Update();
	void Render(sf::RenderWindow& _window);
};

