#include "Tetromino.h"

#include "tetrominos/Tetromino_o.h"
#include "tetrominos/Tetromino_l.h"
#include "tetrominos/Tetromino_j.h"
#include "tetrominos/Tetromino_z.h"
#include "tetrominos/Tetromino_s.h"
#include "tetrominos/Tetromino_t.h"
#include "tetrominos/Tetromino_i.h"

#include <random>
#include <iostream>

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

Tetromino *Tetromino::getRandomTetromino() {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist6(0, 6);

    switch (dist6(rng)) {
        case 0:
            return new Tetromino_o();
        case 1:
            return new Tetromino_i();
        case 2:
            return new Tetromino_t();
        case 3:
            return new Tetromino_s();
        case 4:
            return new Tetromino_z();
        case 5:
            return new Tetromino_j();
        case 6:
            return new Tetromino_l();
        default:
            std::cerr << "Error: Tetromino::getRandomTetromino()" << std::endl;
            exit(1);
    }

}
