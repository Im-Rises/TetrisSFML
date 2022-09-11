#include "Tetris.h"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include <cmath>

Tetris::Tetris() : window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_SIZE,
                                        CELL_SIZE * ROWS * SCREEN_SIZE), PROJECT_NAME),
                   cell(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2)),
                   matrix(COLUMNS, std::vector<TetrisTile>(ROWS)) {
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

        sleepTime(cycleCounter, previousTime);// Limit the framerate and handle cycleCounter
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
                        fallingTetromino.rotate();
                        break;
                    case sf::Keyboard::Down:
//                        fallingTetromino.hardMoveDown(ROWS);
                        break;
                    case sf::Keyboard::Left:
                        fallingTetromino.moveLeft(matrix);
                        break;
                    case sf::Keyboard::Right:
                        fallingTetromino.moveRight(matrix);
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

int Tetris::updateGame(int cycleCounter) {
    if ((INIT_TIME_FALL / difficultyLevel) <= cycleCounter) {
        if (!fallingTetromino.moveDown(matrix)) {

            // Save position of tetromino
            for (auto &tile: fallingTetromino.getTiles()) {
                auto tileX = static_cast<int>(tile.x);
                auto tileY = static_cast<int>(tile.y);
                matrix[tileX][tileY].state = true;
                matrix[tileX][tileY].color = fallingTetromino.getColor();
            }

            // Change tetromino
            fallingTetromino = nextTetromino;
            nextTetromino = Tetromino::getRandomTetromino();

            // Line clearing (to review)
            for (int y = 0; y < ROWS; y++) {
                bool lineFull = true;
                for (int x = 0; x < COLUMNS; x++) {
                    if (!matrix[x][y].state) {
                        lineFull = false;
                        break;
                    }
                }
                if (lineFull) {
                    for (int x = 0; x < COLUMNS; x++) {
                        matrix[x][y].state = false;
                    }
                    for (int y2 = y; y2 > 0; y2--) {
                        for (int x = 0; x < COLUMNS; x++) {
                            matrix[x][y2].state = matrix[x][y2 - 1].state;
                            matrix[x][y2].color = matrix[x][y2 - 1].color;
                        }
                    }
                }
            }
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
    cell.setFillColor(fallingTetromino.getColor());
    for (auto &tile: fallingTetromino.getTiles()) {
        cell.setPosition(CELL_SIZE * tile.x + 1, CELL_SIZE * tile.y + 1);
        window.draw(cell);
    }

    // Shadow tetromino display here

    window.display();
}

void Tetris::sleepTime(int &cycleCounter, std::chrono::steady_clock::time_point &previousTime) {
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
