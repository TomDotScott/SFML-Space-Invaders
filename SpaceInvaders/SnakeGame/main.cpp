#include <iostream>
#include "Constants.h"
#include <SFML/Graphics.hpp>

#include "Game.h"

int main()
{
	srand(time(NULL));
    // All SFML types and functions are contained in the sf namespace

    // Create an instance of the SFML RenderWindow type which represents the display
    // and initialise its size and title text
    sf::RenderWindow window(sf::VideoMode(constants::k_screenWidth, constants::k_screenHeight), "Space Invaders");

	Game game;
	
    // Main loop that continues until we call window.close()
    while (window.isOpen())
    {
        // Handle any pending SFML events
        // These cover keyboard, mouse,joystick etc.
        sf::Event event;
        while (window.pollEvent(event))
        {
          switch(event.type)
          {
            case sf::Event::Closed:
              window.close();
            break;
            default:
              break;
          }
        }
		window.clear();

		game.Update();
		game.Render(window);

		window.display();
    }

    std::cout << "SnakeGame: Finished" << std::endl;

    return 0;
}
