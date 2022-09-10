#include <SFML/Window.hpp>

const unsigned char CELL_SIZE = 8;
const unsigned char COLUMNS = 10;
const unsigned char ROWS = 20;
const unsigned char SCREEN_SIZE = 4;
const unsigned short FRAME_DURATION = 16;

int main() {
	sf::Window window(sf::VideoMode(800, 600), "My window");

	// run the program as long as the window is open
	while (window.isOpen()) {
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event)) {
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}

	return 0;
}
