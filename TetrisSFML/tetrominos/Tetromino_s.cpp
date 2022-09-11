#include "Tetromino_s.h"

Tetromino_s::Tetromino_s() {
    reset();
}

void Tetromino_s::reset() {
    tiles = {
            sf::Vector2f(1, 0),
            sf::Vector2f(2, 0),
            sf::Vector2f(0, 1),
            sf::Vector2f(1, 1)
    };

    color = sf::Color(0, 255, 0);
}

void Tetromino_s::rotate() {

}
