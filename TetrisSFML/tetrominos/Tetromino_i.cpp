#include "Tetromino_i.h"

#include <SFML/Graphics.hpp>

Tetromino_i::Tetromino_i() {
    reset();
}

void Tetromino_i::reset() {
    tiles = {
            sf::Vector2f(0, 0),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 2),
            sf::Vector2f(0, 3)
    };

    color = sf::Color(0, 255, 255);
}

void Tetromino_i::rotate() {

}
