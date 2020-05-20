#include "Game.h"

Game::Game(){
	std::string playerName = "Player.png";
	m_player = new Player(playerName);
}

void Game::Update() {
	m_player->Update();
}

void Game::Render(sf::RenderWindow& _window) const {
	_window.draw(*m_player);
}
