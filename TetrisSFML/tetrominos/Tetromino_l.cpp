#include "Tetromino_l.h"

Tetromino_l::Tetromino_l() {
    reset();
}

void Tetromino_l::reset() {
    tiles = {
            sf::Vector2f(2, 0),
            sf::Vector2f(0, 1),
            sf::Vector2f(1, 1),
            sf::Vector2f(2, 1)
    };

    color = sf::Color(255, 165, 0);
}

void Tetromino_l::rotate() {

}
