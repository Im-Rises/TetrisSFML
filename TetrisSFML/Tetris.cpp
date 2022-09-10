#include "Tetris.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>
#include <iostream>
#include <random>
#include <cmath>

#include "tetrominos/Tetromino_o.h"

Tetris::Tetris() : window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_SIZE, CELL_SIZE * ROWS * SCREEN_SIZE),
                          PROJECT_NAME),
                   cell(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2)) {
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * COLUMNS, CELL_SIZE * ROWS)));
    for (auto &i: matrix) {
        for (auto &j: i) {
            j.state = false;
            j.color = BACKGROUND_COLOR;
        }
    }
}

void Tetris::start() {
    auto previousTime = std::chrono::steady_clock::now();

    while (window.isOpen()) {
        auto deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::steady_clock::now() - previousTime).count();
        handleEvents();
        updateGame();
        refreshScreen();
    }
}

void Tetris::handleEvents() {
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed: {
                window.close();
                break;
            }
            case sf::Event::MouseButtonPressed: {
                auto mousePositionX = sf::Mouse::getPosition(window).x / CELL_SIZE / SCREEN_SIZE;
                auto mousePositionY = sf::Mouse::getPosition(window).y / CELL_SIZE / SCREEN_SIZE;
                matrix[mousePositionX][mousePositionY].state = 1 - matrix[mousePositionX][mousePositionY].state;
                break;
            }
            case sf::Event::KeyPressed: {
                switch (event.key.code) {
                    case sf::Keyboard::Escape:
                        window.close();
                        break;
//                    case sf::Keyboard::Up:
//                        fallingTetromino.rotate();
//                        break;
//                    case sf::Keyboard::Down:
//                        fallingTetromino.hardMoveDown(ROWS);
//                        break;
//                    case sf::Keyboard::Left:
//                        fallingTetromino.moveLeft(COLUMNS);
//                        break;
//                    case sf::Keyboard::Right:
//                        fallingTetromino.moveRight(COLUMNS);
//                        break;
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

void Tetris::updateGame() {
    Tetromino_o tetromino_o;
    bool moveDown = true;
    for (auto &tile: tetromino_o.getTiles()) {
        auto x = (int) tile.x;
        auto y = (int) tile.y;
        if (y == ROWS - 1 || matrix[x][y + 1].state) {
            moveDown = false;
            break;
        }
    }
    if (moveDown) {
        tetromino_o.moveDown(ROWS);
    } else {
        for (auto &tile: tetromino_o.getTiles()) {
            matrix[(int) tile.x][(int) tile.y] = {true, tetromino_o.getColor()};
        }
        tetromino_o = Tetromino_o();
    }
}


void Tetris::refreshScreen() {
    // Background display
    for (auto x = 0; x < COLUMNS; x++) {
        for (auto y = 0; y < ROWS; y++) {
            if (matrix[x][y].state) {
                cell.setFillColor(BACKGROUND_COLOR);
            } else {
                cell.setFillColor(matrix[x][y].color);
            }
            cell.setPosition(CELL_SIZE * x + 1, CELL_SIZE * y + 1);
            window.draw(cell);
        }
    }

    // Falling tetromino display
    for (auto &tile: fallingTetromino.getTiles()) {
        cell.setPosition(CELL_SIZE * tile.x + 1, CELL_SIZE * tile.y + 1);
        cell.setFillColor(fallingTetromino.color);
        window.draw(cell);
    }

    window.display();
}

