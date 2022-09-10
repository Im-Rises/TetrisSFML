#include "Tetromino_s.h"

Tetromino_s::Tetromino_s() {
	tiles = {
		sf::Vector2f(1, 0),
		sf::Vector2f(2, 0),
		sf::Vector2f(0, 1),
		sf::Vector2f(1, 1)
	};
}
