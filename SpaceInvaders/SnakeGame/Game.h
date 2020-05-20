#pragma once
#include "Constants.h"
#include "Player.h"
#include "SFML/Graphics.hpp"

class Game {
public:
	explicit Game();
	void Update();
	void Render(sf::RenderWindow& _window) const;
private:
	Player* m_player;
	int m_score{ 0 };
	int m_highScore{ 0 };
	
};

