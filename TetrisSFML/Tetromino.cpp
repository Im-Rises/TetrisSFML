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
//    return Tetromino('I');
    return {it->first};
}

bool Tetromino::moveDown(const std::vector<std::vector<TetrisTile>> &matrix) {
    for (auto &tile: data.tiles) {
        const int x = cordonateX + tile.x;
        const int y = cordonateY + tile.y;
        if (y >= 0) {
            if (ROWS == (y + 1) ||
                matrix[x][y + 1].state) {
                return false;
            }
        }
    }
    cordonateY += 1;
    return true;
}

bool Tetromino::softMoveDown(const std::vector<std::vector<TetrisTile>> &matrix) {
    return false;
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
    rotateTetrominoHandler(matrix, false);
}

void Tetromino::rotateCounterClockwise(const std::vector<std::vector<TetrisTile>> &matrix) {
    //rotation matrix (x,y) -> (y,-x)
    rotateTetrominoHandler(matrix, true);
}

void Tetromino::rotateTetrominoHandler(const std::vector<std::vector<TetrisTile>> &matrix, bool counterClockwise) {
    if (data.name == "O") {
        return;
    }
    if (data.fullyRotable) {
        rotate(matrix, counterClockwise);
    } else {
        if (rotated) {
            rotate(matrix, false);
            rotated = false;
        } else {
            rotate(matrix, true);
            rotated = true;
        }
    }
}

void Tetromino::rotate(const std::vector<std::vector<TetrisTile>> &matrix, bool counterClockwise) {
    std::vector<sf::Vector2f> newTiles;
    for (auto &tile: data.tiles) {
        if (counterClockwise) {
            newTiles.emplace_back(tile.y, -tile.x);
        } else {
            newTiles.emplace_back(-tile.y, tile.x);
        }
    }
    for (auto &tile: newTiles) {
        const int x = tile.x + cordonateX;
        const int y = tile.y + cordonateY;
        if (y >= 0 && (y >= ROWS || x < 0 || x >= COLUMNS || matrix[x][y].state)) {
            return;
        }
    }
    data.tiles = newTiles;
}

Tetromino Tetromino::getShadowTetromino(const std::vector<std::vector<TetrisTile>> &matrix) {
    Tetromino temp = *this;
    while (temp.moveDown(matrix));
    return temp;
}

std::vector<sf::Vector2f> Tetromino::getTilesPosition() const {
    std::vector<sf::Vector2f> temp;
    for (auto &tile: data.tiles) {
        temp.emplace_back(tile.x + cordonateX, tile.y + cordonateY);
    }
    return temp;
}

std::vector<sf::Vector2f> Tetromino::getTiles() const {
    return tetrominosMap.at(data.name[0]).tiles;
}

sf::Color Tetromino::getColor() const {
    return data.color;
}

std::string Tetromino::getName() const {
    return data.name;
}
