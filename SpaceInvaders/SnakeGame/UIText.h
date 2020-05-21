#pragma once
#include <string>
#include "SFML/Graphics.hpp"


/**
 * \brief UIText is a container for the UI text that will be displayed in each State
 */
struct UIText {
	/**
	 * \brief Constructs a UIText object
	 * \param _string The string value of the UIText to display
	 * \param _colour The colour of the UIText to display
	 * \param _position The position of the UIText to display
	 * \param _font The font of the UIText to display
	 * \param _size The size of the UIText to display
	 */
	UIText(std::string _string, const sf::Color _colour, const sf::Vector2f _position, const sf::Font& _font, const int _size)
		: m_string(std::move(_string)), m_colour(_colour), m_position(_position), m_font(_font), m_characterSize(_size) {
		m_text = sf::Text(m_string, m_font, m_characterSize);
		m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
		m_text.setFillColor(m_colour);
		m_text.setPosition(m_position);
	}
	sf::Text m_text;
	std::string m_string;
	sf::Color m_colour;
	sf::Vector2f m_position;
	sf::Font m_font;
	int m_characterSize;

	/**
	 * \brief Sets the string value of the UIText
	 * \param _newString The new value to display on screen
	 */
	void SetString(const std::string& _newString) {
		m_string = _newString;
		m_text.setString(m_string);
	}

	/**
	 * \brief Sets the position of the UIText
	 * \param _newPosition The new position of the UIText
	 */
	void SetPosition(const sf::Vector2f& _newPosition) {
		m_position = _newPosition;
		m_text.setPosition(m_position);
	}

	/**
	 * \brief Sets the colour of the UIText
	 * \param _colour The new colour of the UIText
	 */
	void SetColour(const sf::Color& _colour) {
		m_colour = _colour;
		m_text.setFillColor(m_colour);
	}
	
	/**
	 * \brief Sets the font of the UIText
	 * \param _newFont The new font of the UIText
	 */
	void SetFont(const sf::Font& _newFont) {
		m_font = _newFont;
		m_text.setFont(m_font);
		m_text.setOrigin(m_text.getGlobalBounds().width / 2, m_text.getGlobalBounds().height / 2);
	}
};
