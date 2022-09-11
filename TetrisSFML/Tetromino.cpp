#include "Tetromino.h"

#include <random>
#include <iostream>


Tetromino::Tetromino(const char &name) {
    data = tetrominosMap.at(name);
}

Tetromino Tetromino::getRandomTetromino() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, tetrominosMap.size() - 1);
    auto it = tetrominosMap.begin();
    std::advance(it, dist6(rng));
    return {it->first};
}

bool Tetromino::moveDown(const std::vector<std::vector<TetrisTile>> &matrix) {
    for (auto &tile: data.tiles) {
        if (matrix[0].size() == (1 + tile.y) || matrix[tile.x][1 + tile.y].state) {
            return false;
        }
    }
    for (auto &tile: data.tiles) {
        tile.y++;
    }
    return true;
}

bool Tetromino::hardMoveDown(const int &rows) {
//    while (moveDown(rows));
    return true;
}


void Tetromino::moveLeft(const std::vector<std::vector<TetrisTile>> &matrix) {
    for (auto &tile: data.tiles) {
        if (0 == tile.x || matrix[tile.x - 1][tile.y].state) {
            return;
        }
    }
    for (auto &tile: data.tiles) {
        tile.x--;
    }
}

void Tetromino::moveRight(const std::vector<std::vector<TetrisTile>> &matrix) {
    for (auto &tile: data.tiles) {
        if (matrix.size() == (1 + tile.x) || matrix[1 + tile.x][tile.y].state) {
            return;
        }
    }
    for (auto &tile: data.tiles) {
        tile.x++;
    }
}

void Tetromino::rotate() {

}

std::vector<sf::Vector2f> Tetromino::getTiles() const {
    return data.tiles;
}

sf::Color Tetromino::getColor() const {
    return data.color;
}
