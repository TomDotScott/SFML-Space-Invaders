#include "Player.h"
#include "Constants.h"

void Player::Update()
{
	m_velocity.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) - sf::Keyboard::isKeyPressed(sf::Keyboard::A);
	Entity::Update(0.1);

	if(getPosition().x < 0)
	{
		move(1, 0);
	}
	if(getPosition().x + getGlobalBounds().width > constants::k_screenWidth)
	{
		move(-1, 0);
	}
}
