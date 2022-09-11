#include <SFML/Graphics.hpp>

#include "Tetromino_z.h"

Tetromino_z::Tetromino_z() {
    reset();
}

void Tetromino_z::reset() {
    tiles = {
            sf::Vector2f(0, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 1),
            sf::Vector2f(2, 1)
    };

    color = sf::Color(255, 0, 0);
}

void Tetromino_z::rotate() {

}
