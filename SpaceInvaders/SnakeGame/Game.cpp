#include "Game.h"

Game::Game() {
	m_player = new Player("Player.png");
	m_player->setPosition({ constants::k_screenWidth / 2 - m_player->getGlobalBounds().width / 2,
		constants::k_screenHeight - 64 });

	for (int i = 0; i < constants::k_alienRows; ++i) {
		std::vector<Alien*> alienRow;
		for (int j = 0; j < constants::k_alienColumns; ++j) {
			auto* alien = new Alien("ClassicAlien_");
			alien->setPosition({ (static_cast<float>(j) * alien->getGlobalBounds().width) + j * constants::k_alienOffsetX, static_cast<float>(i) * constants::k_alienOffsetY });
			alienRow.push_back(alien);
		}
		m_alienGrid.push_back(alienRow);
	}

}

void Game::Update() {
	m_player->Update(m_alienGrid);
	while (m_clock.getElapsedTime().asMilliseconds() >= 1000) {
		MoveAliens();
		for (int i = 0; i < constants::k_alienRows; ++i) {
			for (auto alien : m_alienGrid[i]) {
				alien->Update();
			}
		}
		m_clock.restart();
	}
}

void Game::Render(sf::RenderWindow& _window) const {
	m_player->Render(_window);
	for (int i = 0; i < constants::k_alienRows; ++i) {
		for (int j = 0; j < constants::k_alienColumns; ++j) {
			if (m_alienGrid[i][j]->GetAlive()) {
				_window.draw(*m_alienGrid[i][j]);
			}
		}
	}
}

void Game::MoveAliens() {
	float offset{ 64 };
	if (m_currentDirection == EDirection::eLeft) {
		offset *= -1;
	}

	bool movingDown{ false };

	for (int i = 0; i < constants::k_alienRows; ++i) {
		for (int j = 0; j < constants::k_alienColumns; ++j) {
			if (m_alienGrid[i][j]->GetAlive()) {
				m_alienGrid[i][j]->setPosition(m_alienGrid[i][j]->getPosition().x + offset / 2, m_alienGrid[i][j]->getPosition().y);
				if (m_currentDirection == EDirection::eRight) {
					if (m_alienGrid[i][j]->getPosition().x + offset / 2 >= constants::k_screenWidth) {
						m_currentDirection = EDirection::eLeft;
						movingDown = true;
					}
				} else {
					if (m_alienGrid[i][j]->getPosition().x + offset / 2 < 0) {
						m_currentDirection = EDirection::eRight;
						movingDown = true;
					}
				}
			}
		}
	}

	if (movingDown) {
		for (int i = 0; i < constants::k_alienRows; ++i) {
			for (int j = 0; j < constants::k_alienColumns; ++j) {
				if (m_alienGrid[i][j]->GetAlive()) {
					m_alienGrid[i][j]->setPosition(m_alienGrid[i][j]->getPosition().x - offset / 2, m_alienGrid[i][j]->getPosition().y + abs(offset));
				}
			}
		}
	}
}
