#include "Player.h"
#include "Constants.h"

void Player::Update(const std::vector<std::vector<Alien*>>& _aliensGrid)
{
	m_velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	Entity::Update({ 0.1f , 1});

	if(getPosition().x < 0)
	{
		move(1, 0);
	}
	if(getPosition().x + getGlobalBounds().width > constants::k_screenWidth)
	{
		move(-1, 0);
	}
	if (m_canShoot) {
		Shoot();
	}
	
	if (!m_projectile->GetShootable()) {
		m_projectile->Update(_aliensGrid);
		m_canShoot = false;
	}else
	{
		m_canShoot = true;
	}
}

void Player::Render(sf::RenderWindow& _window) const
{
	if (!m_projectile->GetShootable()) {
		_window.draw(*m_projectile);
	}
	_window.draw(*this);
}

void Player::Shoot()
{
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		if(m_projectile->GetShootable())
		{
			m_projectile->SetShootable(false);
			m_projectile->setPosition({ getPosition().x + getGlobalBounds().width / 2,  getPosition().y});
		}
	}
}
