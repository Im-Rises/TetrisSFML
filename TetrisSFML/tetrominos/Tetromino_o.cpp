#include "Tetromino_o.h"

#include <SFML/Graphics.hpp>

Tetromino_o::Tetromino_o() {
    reset();
}

void Tetromino_o::reset() {
    tiles = {
            sf::Vector2f(0, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(0, 1),
            sf::Vector2f(1, 1)
    };

    for (auto &tile: tiles) {
        tile.x += 4;
    }

    color = sf::Color::Yellow;
}


void Tetromino_o::rotate() {
}
