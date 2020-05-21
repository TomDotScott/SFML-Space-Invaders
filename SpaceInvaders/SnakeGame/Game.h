#pragma once
#include "Alien.h"
#include "Constants.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "Singleton.h"
#include "UIText.h"

class Game final : public Singleton<Game> {
public:
	explicit Game();
	void Update();
	void Render(sf::RenderWindow& _window) const;

	const std::vector<std::vector<Alien*>>& GetGrid() const { return m_alienGrid; }
	Player* GetPlayer() const { return m_player; }
private:
	void MoveAliens();
	
	Player* m_player;
	std::vector<std::vector<Alien*>> m_alienGrid;

	EDirection m_currentDirection{EDirection::eRight};

	sf::Font m_font;
	
	UIText m_scoreText{"Score: ", sf::Color::White, {0, 0}, m_font, 16};
	
	sf::Clock m_clock;
	
	int m_score{ 0 };
};


