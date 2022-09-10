#include "Tetromino_o.h"

#include <SFML/Graphics.hpp>

Tetromino_o::Tetromino_o() {
	tiles = {
		sf::Vector2f(0, 0),
		sf::Vector2f(1, 0),
		sf::Vector2f(0, 1),
		sf::Vector2f(1, 1)
	};
}

void Tetromino_o::moveDown() {
}

void Tetromino_o::rotate() {
}
