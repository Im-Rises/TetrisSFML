#include "Tetromino.h"

Tetromino::Tetromino() {
}

bool Tetromino::moveDown(const int &rows) {
    for (auto &tile: tiles) {
        if (rows <= (1 + tile.y)) {
            return false;
        }
    }

    for (auto &tile: tiles) {
        tile.y++;
    }
    return true;
}

bool Tetromino::hardMoveDown(const int &rows) {
    while (moveDown(rows));
    return true;
}


bool Tetromino::moveLeft(const int &columns) {
    for (auto &tile: tiles) {
        if (tile.x <= 0) {
            return false;
        }
    }

    for (auto &tile: tiles) {
        tile.x--;
    }

    return false;
}

bool Tetromino::moveRight(const int &columns) {
    for (auto &tile: tiles) {
        if (columns <= (1 + tile.x)) {
            return false;
        }
    }

    for (auto &tile: tiles) {
        tile.x++;
    }

    return false;
}

void Tetromino::rotate() {

}

std::vector<sf::Vector2f> Tetromino::getTiles() const {
    return tiles;
}

sf::Color Tetromino::getColor() const {
    return color;
}
