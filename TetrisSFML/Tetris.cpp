#include "Tetris.h"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include <cmath>

#include "tetrominos/Tetromino_o.h"

Tetris::Tetris() : window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_SIZE,
                                        CELL_SIZE * ROWS * SCREEN_SIZE), PROJECT_NAME),
                   cell(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2)) {
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * COLUMNS, CELL_SIZE * ROWS)));
    difficultyLevel = INIT_LEVEL;
}

void Tetris::start() {
    auto previousTime = std::chrono::steady_clock::now();
    int cycleCounter = 0;

    while (window.isOpen()) {

        handleEvents();//Update inputs

        cycleCounter = updateGame(cycleCounter);//Update falling tetromino

        refreshScreen();//Update screen

        // Limit the framerate to 60 frames per second
        cycleCounter++;
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - previousTime).count();
        while (deltaTime < FRAME_DURATION) {
            deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                    std::chrono::steady_clock::now() - previousTime).count();
            // Waiting while we reach 16ms
        }
        previousTime = std::chrono::steady_clock::now();
    }
}

void Tetris::handleEvents() {
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
                    case sf::Keyboard::Up:
                        fallingTetromino->rotate();
                        break;
                    case sf::Keyboard::Down:
//                        fallingTetromino.hardMoveDown(ROWS);
                        break;
                    case sf::Keyboard::Left:
                        fallingTetromino->moveLeft(COLUMNS);
                        break;
                    case sf::Keyboard::Right:
                        fallingTetromino->moveRight(COLUMNS);
                        break;
                    default:
                        break;
                }
                break;
            }
            default: {
                break;
            }
        }
    }
}

int Tetris::updateGame(const int &cycleCounter) {
    if ((INIT_TIME_FALL / difficultyLevel) <= cycleCounter) {
        bool moveDown = true;
        for (auto &tile: fallingTetromino->getTiles()) {
            auto x = (int) tile.x;
            auto y = (int) tile.y;
            if (y == (ROWS - 1) || matrix[x][y + 1].state) {
                moveDown = false;
                break;
            }
        }
        if (moveDown) {
            fallingTetromino->moveDown(ROWS);
        } else {
            for (auto &tile: fallingTetromino->getTiles()) {
                matrix[(int) tile.x][(int) tile.y] = {true, fallingTetromino->getColor()};
            }
//            fallingTetromino->reset();
            fallingTetromino = Tetromino::getRandomTetromino();
        }
        return 0;
    }
    return cycleCounter;
}

void Tetris::refreshScreen() {
    // Background display
    for (auto x = 0; x < COLUMNS; x++) {
        for (auto y = 0; y < ROWS; y++) {
            if (matrix[x][y].state) {
                cell.setFillColor(matrix[x][y].color);
            } else {
                cell.setFillColor(BACKGROUND_COLOR);
            }
            cell.setPosition(CELL_SIZE * x + 1, CELL_SIZE * y + 1);
            window.draw(cell);
        }
    }

    // Falling tetromino display
    for (auto &tile: fallingTetromino->getTiles()) {
        cell.setPosition(CELL_SIZE * tile.x + 1, CELL_SIZE * tile.y + 1);
        cell.setFillColor(fallingTetromino->getColor());
        window.draw(cell);
    }

    // Shadow tetromino display here

    window.display();
}
