#include "Alien.h"

void Alien::Update()
{
	if(m_currentFrame == m_totalFrames)
	{
		m_currentFrame = 0;
	}
	
	if(getPosition() != m_previousPosition)
	{
		std::cout << "Changing textures" << "Current Frame : " << m_currentFrame << std::endl;
		setTexture(m_textures[m_currentFrame]);
	}

	m_currentFrame++;
}

void Alien::Render(sf::RenderWindow& _window)
{
	_window.draw(*this);
}
