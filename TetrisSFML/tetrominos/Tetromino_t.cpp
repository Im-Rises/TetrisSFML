#include "Tetromino_t.h"

Tetromino_t::Tetromino_t() {
	tiles = {
		sf::Vector2f(0, 0),
		sf::Vector2f(1, 0),
		sf::Vector2f(2, 0),
		sf::Vector2f(1, 1)
	};
}
