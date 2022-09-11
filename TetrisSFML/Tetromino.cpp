#include "Tetromino.h"

#include <random>
#include <iostream>


Tetromino::Tetromino(const char &name) {
    data = tetrominosMap.at(name);
}

void Tetromino::reset() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 6);
}

void Tetromino::moveDown(const int &rows) {
    for (auto &tile: this->data.tiles) {
        tile.y++;
    }
}

bool Tetromino::hardMoveDown(const int &rows) {
//    while (moveDown(rows));
    return true;
}


bool Tetromino::moveLeft(const int &columns) {
    for (auto &tile: data.tiles) {
        if (tile.x <= 0) {
            return false;
        }
    }

    for (auto &tile: data.tiles) {
        tile.x--;
    }

    return false;
}

bool Tetromino::moveRight(const int &columns) {
    for (auto &tile: data.tiles) {
        if (columns <= (1 + tile.x)) {
            return false;
        }
    }

    for (auto &tile: data.tiles) {
        tile.x++;
    }

    return false;
}

void Tetromino::rotate() {

}

std::vector<sf::Vector2f> Tetromino::getTiles() const {
    return data.tiles;
}

sf::Color Tetromino::getColor() const {
    return data.color;
}

Tetromino Tetromino::getRandomTetromino() {
//    std::random_device dev;
//    std::mt19937 rng(dev());
//    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, tetrominosMap.size());
    return {Tetromino('I')};
}
