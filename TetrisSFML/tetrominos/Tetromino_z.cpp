#include <SFML/Graphics.hpp>

#include "Tetromino_z.h"

Tetromino_z::Tetromino_z() {
	tiles = {
		sf::Vector2f(0, 0),
		sf::Vector2f(1, 0),
		sf::Vector2f(1, 1),
		sf::Vector2f(2, 1)
	};
}
