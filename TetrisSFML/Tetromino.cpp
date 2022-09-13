#include "Tetromino.h"

#include <random>
#include <iostream>

Tetromino::Tetromino(const char &name) {
    data = tetrominosMap.at(name);
    cordonateX = (COLUMNS / 2) - 1;
    cordonateY = 0;
}

Tetromino Tetromino::getRandomTetromino() {
    // Random number generator
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, tetrominosMap.size() - 1);

    // Get random key from map
    auto it = tetrominosMap.begin();
    std::advance(it, dist6(rng));

    // Call Tetromino constructor with random key from tetrominosMap
    return Tetromino('I');

    return {it->first};
}

bool Tetromino::moveDown(const std::vector<std::vector<TetrisTile>> &matrix) {
    for (auto &tile: data.tiles) {
        if (tile.y >= 0) {
            const int x = cordonateX + tile.x;
            const int y = cordonateY + tile.y;
            if (ROWS == (y + 1) ||
                matrix[x][y + 1].state) {
                return false;
            }
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
        const int x = tile.x + cordonateX;
        const int y = tile.y + cordonateY;
        if (y >= 0 && (x == 0 || matrix[x - 1][y].state)) {
            return;
        }
    }
    cordonateX--;
}

void Tetromino::moveRight(const std::vector<std::vector<TetrisTile>> &matrix) {
    for (auto &tile: data.tiles) {
        const int x = tile.x + cordonateX;
        const int y = tile.y + cordonateY;
        if (y >= 0 && (x == COLUMNS - 1 || matrix[x + 1][y].state)) {
            return;
        }
    }
    cordonateX++;
}

void Tetromino::rotateClockwise(const std::vector<std::vector<TetrisTile>> &matrix) {
    //rotation matrix (x,y) -> (-y,x)
    if (data.name == "O") {
        return;
    }
    if (data.fullyRotable) {
        rotate(false);
    } else {
        if (rotated) {
            rotate(false);
            rotated = false;
        } else {
            rotate(true);
            rotated = true;
        }
    }
}

void Tetromino::rotateCounterClockwise(const std::vector<std::vector<TetrisTile>> &matrix) {
    //rotation matrix (x,y) -> (y,-x)
    if (data.name == "O") {
        return;
    }
    if (data.fullyRotable) {
        rotate(true);
    } else {
        if (rotated) {
            rotate(true);
            rotated = false;
        } else {
            rotate(false);
            rotated = true;
        }
    }
}

void Tetromino::rotate(bool counterClockwise) {

    std::vector<sf::Vector2f> newTiles;
    for (auto &tile: data.tiles) {
        if (counterClockwise) {
            newTiles.emplace_back(tile.y, -tile.x);
        } else {
            newTiles.emplace_back(-tile.y, tile.x);
        }
    }
    for (auto &tile: newTiles) {
        if (tile.x + cordonateX < 0 || tile.x + cordonateX >= COLUMNS ||
            tile.y + cordonateY >= ROWS) {
            return;
        }
    }
    data.tiles = newTiles;
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
