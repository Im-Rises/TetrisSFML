#include "Tetris.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <chrono>


#include "Tetromino.h"
#include "tetrominos/Tetromino_o.h"

Tetris::Tetris() {
}

void Tetris::start() {
    sf::Color backgroundColor(rgbBgColor[0], rgbBgColor[1], rgbBgColor[2]);
    sf::RenderWindow window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_SIZE, CELL_SIZE * ROWS * SCREEN_SIZE),
                            PROJECT_NAME);
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * COLUMNS, CELL_SIZE * ROWS)));

    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE - 2, CELL_SIZE - 2));
    std::vector<std::vector<bool>> matrix(COLUMNS, std::vector<bool>(ROWS, false));
    std::vector<std::vector<sf::Color>> matrixColor(COLUMNS, std::vector<sf::Color>(ROWS, backgroundColor));

    auto previousTime = std::chrono::steady_clock::now();
    unsigned int lagInput = 0;
    Tetromino_o tetromino_o;
    while (window.isOpen()) {
        auto deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(
                std::chrono::steady_clock::now() - previousTime).count();

        // Handle tetrominos
        bool moveDown = true;
        for (auto &tile: tetromino_o.getTiles()) {
            auto x = tile.x;
            auto y = tile.y;
            if (y == ROWS - 1 || matrix[x][y + 1]) {
                moveDown = false;
                break;
            }
        }
        if (moveDown) {
            tetromino_o.moveDown(ROWS);
        } else {
            for (auto &tile: tetromino_o.getTiles()) {
                auto x = tile.x;
                auto y = tile.y;
                matrix[x][y] = 1;
                matrixColor[x][y] = tetromino_o.getColor();
            }
            tetromino_o = Tetromino_o();
        }

        // Display
        for (auto x = 0; x < COLUMNS; x++) {
            for (auto y = 0; y < ROWS; y++) {
                if (matrix[x][y] == 0) {
                    cell.setFillColor(backgroundColor);
                } else {
                    cell.setFillColor(matrixColor[x][y]);
                }
                cell.setPosition(CELL_SIZE * x + 1, CELL_SIZE * y + 1);
                window.draw(cell);
            }
        }

        for (auto &tile: tetromino_o.tiles) {
            cell.setPosition(CELL_SIZE * tile.x + 1, CELL_SIZE * tile.y + 1);
            cell.setFillColor(tetromino_o.color);
            window.draw(cell);
        }

        window.display();

        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            window.close();
                            break;
                        case sf::Keyboard::Up:
                            //Rotate
                            break;
                        case sf::Keyboard::Down:
                            tetromino_o.hardMoveDown(ROWS);
                            break;
                        case sf::Keyboard::Left:
                            tetromino_o.moveLeft(COLUMNS);
                            break;
                        case sf::Keyboard::Right:
                            tetromino_o.moveRight(COLUMNS);
                            break;

                    }
                    break;
                case sf::Event::MouseButtonPressed:
                    auto mousePositionX = sf::Mouse::getPosition(window).x / CELL_SIZE / SCREEN_SIZE;
                    auto mousePositionY = sf::Mouse::getPosition(window).y / CELL_SIZE / SCREEN_SIZE;
                    matrix[mousePositionX][mousePositionY] = 1 - matrix[mousePositionX][mousePositionY];
                    break;
            }
        }
    }
}
