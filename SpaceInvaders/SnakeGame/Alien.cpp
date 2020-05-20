#include "Alien.h"

void Alien::Update()
{
	if(m_currentFrame == m_totalFrames)
	{
		m_currentFrame = 0;
	}
	
	if(getPosition() != m_previousPosition)
	{
		setTexture(m_textures[m_currentFrame]);
	}

	m_currentFrame++;

}

void Alien::Render(sf::RenderWindow& _window)
{
	_window.draw(*this);
}
