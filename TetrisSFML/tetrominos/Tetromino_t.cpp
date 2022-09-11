#include "Tetromino_t.h"

Tetromino_t::Tetromino_t() {
    reset();
}


void Tetromino_t::reset() {
    tiles = {
            sf::Vector2f(0, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(2, 0),
            sf::Vector2f(1, 1)
    };

    color = sf::Color(128, 0, 128);
}


void Tetromino_t::rotate() {

}
