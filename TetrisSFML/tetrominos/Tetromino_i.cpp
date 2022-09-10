#include "Tetromino_i.h"

#include <SFML/Graphics.hpp>

Tetromino_i::Tetromino_i() {
	tiles = {
		sf::Vector2f(0, 0),
		sf::Vector2f(0, 1),
		sf::Vector2f(0, 2),
		sf::Vector2f(0, 3)
	};
}
