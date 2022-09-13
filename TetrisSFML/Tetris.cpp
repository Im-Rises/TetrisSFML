#include "Tetris.h"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>
#include <cmath>

Tetris::Tetris() : window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_SIZE,
                                        CELL_SIZE * ROWS * SCREEN_SIZE), PROJECT_NAME),
                   cell(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2)) {
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * COLUMNS, CELL_SIZE * ROWS)));
    reset();
}

void Tetris::reset() {
    matrix = std::vector<std::vector<TetrisTile>>(COLUMNS, std::vector<TetrisTile>(ROWS));
    fallingTetromino = Tetromino::getRandomTetromino();
    nextTetromino = Tetromino::getRandomTetromino();
    difficultyLevel = INIT_LEVEL;
    lines = 0;
}

void Tetris::start() {
    auto previousTime = std::chrono::steady_clock::now();
    auto previousFpsTime = std::chrono::steady_clock::now();
    while (window.isOpen()) {

        handleEvents();//Update inputs

        updateGame(previousTime);//Update falling tetromino

        refreshScreen();//Update screen

        handleFps(previousFpsTime);//Handle fps display and calculation
    }
}

void Tetris::handleEvents() {
    static bool rotationPressed = false;

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
                    case sf::Keyboard::D:
                        if (!rotationPressed) {
                            fallingTetromino.rotateClockwise(matrix);
                            rotationPressed = true;
                        }
                        break;
                    case sf::Keyboard::S:
                        if (!rotationPressed) {
                            fallingTetromino.rotateCounterClockwise(matrix);
                            rotationPressed = true;
                        }
                        break;
                    case sf::Keyboard::Up:
                        fallingTetromino.hardMoveDown(matrix);
                        break;
                    case sf::Keyboard::Down: {
                        softDropValue = SOFT_DROP_TIME_DIVIDER;
                        break;
                    }
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
            case sf::Event::KeyReleased: {
                switch (event.key.code) {
                    case sf::Keyboard::D:
                    case sf::Keyboard::S: {
                        rotationPressed = false;
                        break;
                    }
                    case sf::Keyboard::Down: {
                        softDropValue = 1;
                        break;
                    }
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

void Tetris::updateGame(std::chrono::steady_clock::time_point &previousTime) {
    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - previousTime).count();
    if (deltaTime > INIT_TIME_FALL / difficultyLevel / softDropValue) {
        previousTime = std::chrono::steady_clock::now();
        if (!fallingTetromino.moveDown(matrix)) {
            // Save position of tetromino
            for (auto &tile: fallingTetromino.getTiles()) {
                if (tile.y >= 0) {
                    matrix[tile.x][tile.y].state = true;
                    matrix[tile.x][tile.y].color = fallingTetromino.getColor();
                }
            }

            // Change tetromino
            fallingTetromino = nextTetromino;
            nextTetromino = Tetromino::getRandomTetromino();

            // Line clearing
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
                    lines++;
                }
            }

            // Handle loose
            for (int x = 0; x < COLUMNS; x++) {
                if (matrix[x][0].state) {
                    reset();
                    break;
                }
            }
        }
        return;
    }
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
        if (tile.y >= 0) {
            cell.setPosition(CELL_SIZE * tile.x + 1, CELL_SIZE * tile.y + 1);
            window.draw(cell);
        }
    }

    // Shadow tetromino display here

    window.display();
    fps++;
}

void Tetris::handleFps(std::chrono::steady_clock::time_point &fpsPreviousTime) {
    auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::steady_clock::now() - fpsPreviousTime).count();
    if (deltaTime > 1000) {
        window.setTitle(PROJECT_NAME + " - FPS: " + std::to_string(fps));
        fps = 0;
        fpsPreviousTime = std::chrono::steady_clock::now();
    }
}
