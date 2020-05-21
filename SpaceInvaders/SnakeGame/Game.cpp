#include "Game.h"

Game::Game() {
	m_player = new Player("Player.png");
	m_player->setPosition({
		static_cast<float>(constants::k_screenWidth) / 2 - m_player->getGlobalBounds().width / 2,
		constants::k_screenHeight - 64 });

	for (int i = 0; i < constants::k_alienRows; ++i) {
		std::vector<Entity*> alienRow;
		for (int j = 0; j < constants::k_alienColumns; ++j) {
			Alien* alien;
			//decide the alien type
			if (i % constants::k_alienRows == 0) {
				alien = new Alien("Row_1_");
			} else if (i % constants::k_alienRows == 1 || i % constants::k_alienRows == 2) {
				alien = new Alien("Row_2_");

			} else {
				alien = new Alien("Row_4_");

			}
			alien->setPosition({ (static_cast<float>(j) * alien->getGlobalBounds().width) + j * constants::k_alienOffsetX, static_cast<float>(i + 1) * constants::k_alienOffsetY });
			alienRow.push_back(alien);
		}
		m_alienGrid.push_back(alienRow);
	}

}

void Game::Update() {
	m_player->Update(m_alienGrid);
	for(auto row : m_alienGrid)
	{
		for(auto alien : row)
		{
			Alien* alienP = dynamic_cast<Alien*>(alien);
			if(alienP)
			{
				alienP->Update(m_alienGrid, m_player);
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
					if(rand() % 100 == 1)
					{
						std::cout << "SHOOT" << std::endl;
						p->Shoot();
					}
				}
				p->Update();
			}
		}
		m_clock.restart();
	}
}

void Game::Render(sf::RenderWindow& _window) const {
	m_player->Render(_window);
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
