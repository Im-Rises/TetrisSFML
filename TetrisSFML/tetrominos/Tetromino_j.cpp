//
// Created by Quentin on 09/09/2022.
//

#include "Tetromino_j.h"

Tetromino_j::Tetromino_j() {
    reset();
}

void Tetromino_j::reset() {
    tiles = {
            sf::Vector2f(0, 0),
            sf::Vector2f(0, 1),
            sf::Vector2f(1, 1),
            sf::Vector2f(2, 1)
    };

    color = sf::Color(0, 0, 255);
}

void Tetromino_j::rotate() {

}
