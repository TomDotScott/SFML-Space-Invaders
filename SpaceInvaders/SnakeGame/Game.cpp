#include "Game.h"

Game::Game(){
	m_player = new Player("Player.png");
	m_player->setPosition({ constants::k_screenWidth / 2 - m_player->getGlobalBounds().width / 2, 
		constants::k_screenHeight - 64 });

	for(int i = 0; i < constants::k_alienRows; ++i)
	{
		std::vector<Alien*> alienRow;
		for(int j = 0; j < constants::k_alienColumns; ++j)
		{
			auto* alien = new Alien("ClassicAlien_1.png");
			alien->setPosition({ (static_cast<float>(j) * alien->getGlobalBounds().width) + j * constants::k_alienOffsetX, static_cast<float>(i) * constants::k_alienOffsetY });
			alienRow.push_back(alien);
		}
		m_alienGrid.push_back(alienRow);
	}

}

void Game::Update() {
	m_player->Update();
}

void Game::Render(sf::RenderWindow& _window) const {
	m_player->Render(_window);
	for(int i = 0; i < constants::k_alienRows; ++i)
	{
		for(int j = 0; j < constants::k_alienColumns; ++j)
		{
			_window.draw(*m_alienGrid[i][j]);
		}
	}
}
