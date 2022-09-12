#include "Tetromino.h"

#include <random>
#include <iostream>


Tetromino::Tetromino(const char &name) {
    data = tetrominosMap.at(name);
    cordonateX = COLUMNS / 2;
    cordonateY = 0;
}

Tetromino Tetromino::getRandomTetromino() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, tetrominosMap.size() - 1);
    auto it = tetrominosMap.begin();
    std::advance(it, dist6(rng));
//    return Tetromino('T');
    return {it->first};
}

bool Tetromino::moveDown(const std::vector<std::vector<TetrisTile>> &matrix) {
    for (auto &tile: data.tiles) {
        if (matrix[0].size() == (1 + tile.y + cordonateY) ||
            matrix[tile.x + cordonateX][1 + tile.y + cordonateY].state) {
            return false;
        }
    }
    cordonateY += 1;
    return true;
}

bool Tetromino::hardMoveDown(const std::vector<std::vector<TetrisTile>> &matrix) {
    while (moveDown(matrix));
    return true;
}


void Tetromino::moveLeft(const std::vector<std::vector<TetrisTile>> &matrix) {
    for (auto &tile: data.tiles) {
        if (0 == (tile.x + cordonateX) || matrix[tile.x + cordonateX - 1][tile.y + cordonateY].state) {
            return;
        }
    }
    cordonateX--;
}

void Tetromino::moveRight(const std::vector<std::vector<TetrisTile>> &matrix) {
    for (auto &tile: data.tiles) {
        if (matrix.size() == (1 + tile.x + cordonateX) || matrix[1 + tile.x + cordonateX][tile.y + cordonateY].state) {
            return;
        }
    }
    cordonateX++;
}

void Tetromino::rotateClockwise(const std::vector<std::vector<TetrisTile>> &matrix) {
    //rotation matrix (x,y) -> (-y,x)
    for (auto &tile: data.tiles) {
        int x = tile.x;
        int y = tile.y;
        tile.x = -y;
        tile.y = x;
    }
}

void Tetromino::rotateCounterClockwise(const std::vector<std::vector<TetrisTile>> &matrix) {
    //rotation matrix (x,y) -> (y,-x)
    for (auto &tile: data.tiles) {
        int x = tile.x;
        int y = tile.y;
        tile.x = y;
        tile.y = -x;
    }
}

std::vector<sf::Vector2f> Tetromino::getTiles() const {
    std::vector<sf::Vector2f> temp;
    for (auto &tile: data.tiles) {
        temp.emplace_back(tile.x + cordonateX, tile.y + cordonateY);
    }
    return temp;
}

sf::Color Tetromino::getColor() const {
    return data.color;
}
