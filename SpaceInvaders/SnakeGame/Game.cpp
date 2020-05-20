#include "Game.h"

Game::Game(){
	std::string playerName = "Player.png";
	m_player = new Player(playerName);
	m_player->setPosition({ constants::k_screenWidth / 2 - m_player->getGlobalBounds().width / 2, 
		constants::k_screenHeight - 64 });
}

void Game::Update() {
	m_player->Update();
}

void Game::Render(sf::RenderWindow& _window) const {
	m_player->Render(_window);
}
