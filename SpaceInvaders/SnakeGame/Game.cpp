#include "Game.h"

#include "SoundManager.h"

Game::Game() {
	SoundManager::Instance().PlayMusic("Music");
	m_font.loadFromFile("Resources/Graphics/gamefont.ttf");
	m_scoreText.SetFont(m_font);
	m_scoreText.SetPosition({m_scoreText.m_text.getGlobalBounds().width / 2, m_scoreText.m_text.getGlobalBounds().height / 2});
	m_player = new Player("Player.png");
	m_player->setPosition({
		static_cast<float>(constants::k_screenWidth) / 2 - m_player->getGlobalBounds().width / 2,
		constants::k_screenHeight - 64 });

	for (int i = 0; i < constants::k_alienRows; ++i) {
		std::vector<Alien*> alienRow;
		for (int j = 0; j < constants::k_alienColumns; ++j) {
			Alien* alien;
			//decide the alien type
			if (i % constants::k_alienRows == 0) {
				alien = new Alien("Row_1_", 30);
			} else if (i % constants::k_alienRows == 1 || i % constants::k_alienRows == 2) {
				alien = new Alien("Row_2_", 20);

			} else {
				alien = new Alien("Row_4_", 10);

			}
			alien->setPosition({ (static_cast<float>(j) * alien->getGlobalBounds().width) + j * constants::k_alienOffsetX, static_cast<float>(i + 1) * constants::k_alienOffsetY });
			alienRow.push_back(alien);
		}
		m_alienGrid.push_back(alienRow);
	}

}

void Game::Update() {
	m_player->Update();
	for(const auto& row : m_alienGrid)
	{
		for(auto alien : row)
		{
			auto* alienP = dynamic_cast<Alien*>(alien);
			if(alienP)
			{
				alienP->Update();
			}
		}
	}
	
	while (m_clock.getElapsedTime().asMilliseconds() >= 1000) {
		MoveAliens();
		for (int i = 0; i < constants::k_alienRows; ++i) {
			for (auto alien : m_alienGrid[i]) {
				auto* p = dynamic_cast<Alien*>(alien);
				if(p->GetCanShoot())
				{
					if(rand() % 100 <= 5)
					{
						p->Shoot();
					}
				}
				p->Animate();
			}
		}
		m_clock.restart();
	}
}

void Game::Render(sf::RenderWindow& _window) const {
	m_player->Render(_window);
	_window.draw(m_scoreText.m_text);
	for (int i = 0; i < constants::k_alienRows; ++i) {
		for (int j = 0; j < constants::k_alienColumns; ++j) {
			auto* alien = dynamic_cast<Alien*>(m_alienGrid[i][j]);
			if (alien->GetAlive()) {
				alien->Render(_window);
			}
		}
	}
}

void Game::MoveAliens() {
	float offset{ 32 };
	if (m_currentDirection == EDirection::eLeft) {
		offset *= -1;
	}

	bool movingDown{ false };

	for (int i = 0; i < constants::k_alienRows; ++i) {
		for (int j = 0; j < constants::k_alienColumns; ++j) {
			auto* alien = dynamic_cast<Alien*>(m_alienGrid[i][j]);
			if (alien->GetAlive()) {
				m_alienGrid[i][j]->setPosition(m_alienGrid[i][j]->getPosition().x + offset / 2, m_alienGrid[i][j]->getPosition().y);
				if (m_currentDirection == EDirection::eRight) {
					if (m_alienGrid[i][j]->getPosition().x + offset >= constants::k_screenWidth) {
						m_currentDirection = EDirection::eLeft;
						movingDown = true;
					}
				} else {
					if (m_alienGrid[i][j]->getPosition().x - offset / 4 < 0) {
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
				auto* alien = dynamic_cast<Alien*>(m_alienGrid[i][j]);
				if (alien->GetAlive()) {
					m_alienGrid[i][j]->setPosition(m_alienGrid[i][j]->getPosition().x - offset / 2, m_alienGrid[i][j]->getPosition().y + abs(offset));
				}
			}
		}
	}
}
