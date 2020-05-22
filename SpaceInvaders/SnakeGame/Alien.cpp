#include "Alien.h"

#include "Game.h"
#include "SoundManager.h"

void Alien::Update() {
	if (!m_projectile->GetShootable()) {
		m_projectile->Update();
		m_canShoot = false;
	} else {
		m_canShoot = true;
	}
}


void Alien::Animate() {
	if (m_currentFrame == m_totalFrames) {
		m_currentFrame = 0;
	}

	if (getPosition() != m_previousPosition) {
		setTexture(m_textures[m_currentFrame]);
		m_previousPosition = getPosition();
	}

	m_currentFrame++;
}

void Alien::Render(sf::RenderWindow& _window) const {
	if (!m_projectile->GetShootable()) {
		_window.draw(*m_projectile);
	}
	_window.draw(*this);
}

void Alien::Shoot() const {
	if (m_projectile->GetShootable()) {
		std::cout << "PROJECTILE SHOT" << std::endl;
		m_projectile->SetShootable(false);
		m_projectile->RandomiseSprite();
		m_projectile->setPosition({ getPosition().x + getGlobalBounds().width / 2,  getPosition().y });
	}
}

void Alien::SetAlive(const bool _status) {
	
	m_alive = _status;
	Game::Instance().AddScore(m_points);
	SoundManager::Instance().PlaySFX("AlienDeath");
}
