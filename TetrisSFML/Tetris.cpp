#include "Tetris.h"

#include <SFML/Graphics.hpp>
#include <chrono>
#include <iostream>
#include <random>

Tetris::Tetris() : window(sf::VideoMode(CELL_SIZE * COLUMNS * SCREEN_SIZE * 2,
                                        CELL_SIZE * ROWS * SCREEN_SIZE), PROJECT_NAME,
                          sf::Style::Titlebar | sf::Style::Close),
                   cell(sf::Vector2f(CELL_SIZE - 1, CELL_SIZE - 1)),
                   previewRectangle(sf::Vector2f(5 * CELL_SIZE, 5 * CELL_SIZE)) {
    window.setView(sf::View(sf::FloatRect(0, 0, CELL_SIZE * COLUMNS * 2, CELL_SIZE * ROWS + 1)));

    int x = (3.0f / 2) * CELL_SIZE * COLUMNS - 2.5 * CELL_SIZE;
    int y = (2.0f / 5) * CELL_SIZE * COLUMNS - 2.5 * CELL_SIZE;
    previewRectangle.setFillColor(sf::Color(0, 0, 0));
    previewRectangle.setOutlineThickness(-1);
    previewRectangle.setPosition(x, y);

    if (!font.loadFromFile(FONT_PATH)) {
        exit(1);
    }

    int textY = CELL_SIZE * ROWS / 2;
    int fontSize = std::floor(CELL_SIZE * 1.5);

    linesText.setFont(font);
    linesText.setCharacterSize(fontSize);
    linesText.setFillColor(sf::Color::White);
    linesText.setPosition(x, textY);

    levelText.setFont(font);
    levelText.setCharacterSize(fontSize);
    levelText.setFillColor(sf::Color::White);
    levelText.setPosition(x, textY + CELL_SIZE * 2);

    squareLineClearEffectSize = cell.getSize();

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
    auto animationPreviousTime = std::chrono::steady_clock::now();
    while (window.isOpen()) {

        handleEvents();//Update inputs

        updateGame(previousTime);//Update falling tetromino

        refreshScreen(animationPreviousTime);//Update screen

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
                            fallingTetromino.rotateCounterClockwise(matrix);
                            rotationPressed = true;
                        }
                        break;
                    case sf::Keyboard::S:
                        if (!rotationPressed) {
                            fallingTetromino.rotateClockwise(matrix);
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
    if (linesToDoClearEffect.empty()) {
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - previousTime).count();
        if (deltaTime > INIT_TIME_FALL / difficultyLevel / softDropValue) {
            previousTime = std::chrono::steady_clock::now();
            if (!fallingTetromino.moveDown(matrix)) {
                // Save position of tetromino
                for (auto &tile: fallingTetromino.getTilesPosition()) {
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
                        previousMatrix = matrix;
                        linesToDoClearEffect.push_back(y);
                        for (int y2 = y; y2 > 0; y2--) {
                            for (int x = 0; x < COLUMNS; x++) {
                                matrix[x][y2].state = matrix[x][y2 - 1].state;
                                matrix[x][y2].color = matrix[x][y2 - 1].color;
                            }
                        }
                        lines++;
                    }
                }

                // Handle level
                static int previousLinesLevelUp = 0;
                if (lines - previousLinesLevelUp > NB_LINES_DIFFICULTY_CHANGE && difficultyLevel <= MAX_LEVEL) {
                    difficultyLevel++;
                    previousLinesLevelUp = lines;
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
}

void Tetris::refreshScreen(std::chrono::steady_clock::time_point &animationPreviousTime) {
    window.clear();

    // Background display
    if (linesToDoClearEffect.empty()) {
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
    } else {
        for (auto x = 0; x < COLUMNS; x++) {
            for (auto y = 0; y < ROWS; y++) {
                if (previousMatrix[x][y].state &&
                    std::find(linesToDoClearEffect.begin(), linesToDoClearEffect.end(), y) ==
                    linesToDoClearEffect.end()) {
                    cell.setFillColor(previousMatrix[x][y].color);
                } else {
                    cell.setFillColor(BACKGROUND_COLOR);
                }
                cell.setPosition(CELL_SIZE * x + 1, CELL_SIZE * y + 1);
                window.draw(cell);

            }
        }
    }

    // Next tetromino preview display
    window.draw(previewRectangle);
    for (auto &tile: nextTetromino.getTiles()) {
        cell.setFillColor(nextTetromino.getColor());
        std::string name = nextTetromino.getName();
        float x = (3.0f / 2) * CELL_SIZE * COLUMNS - tile.x * CELL_SIZE;
        float y = (2.0f / 5) * CELL_SIZE * COLUMNS - tile.y * CELL_SIZE;
        if (name == "O") {
            cell.setPosition(x, y);
        } else if (name == "I") {
            cell.setPosition(x, y - CELL_SIZE / 2);
        } else {
            cell.setPosition(x - CELL_SIZE / 2, y);
        }

        window.draw(cell);
    }


    // Falling tetromino display
    cell.setFillColor(fallingTetromino.getColor());
    for (auto &tile: fallingTetromino.getTilesPosition()) {
        if (tile.y >= 0) {
            cell.setPosition(CELL_SIZE * tile.x + 1, CELL_SIZE * tile.y + 1);
            window.draw(cell);
        }
    }

    // Shadow tetromino display here
    Tetromino shadow = fallingTetromino.getShadowTetromino(matrix);
    sf::Color shadowColor = shadow.getColor();
    shadowColor.a = 120;
    cell.setFillColor(shadowColor);
    for (auto &tile: shadow.getTilesPosition()) {
        cell.setPosition(CELL_SIZE * tile.x + 1, CELL_SIZE * tile.y + 1);
        window.draw(cell);
    }

    // Display score
    linesText.setString("Lines: " + std::to_string(lines));
    window.draw(linesText);

    // Display level
    levelText.setString("Level: " + std::to_string(difficultyLevel));
    window.draw(levelText);

    // Display lines clear effect
    if (!linesToDoClearEffect.empty()) {
        auto delatime = std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::steady_clock::now() - animationPreviousTime).count();

        // Decrease the timer to decrease rectange size
        if (delatime > TIME_EFFECT_FRAME) {
            animationPreviousTime = std::chrono::steady_clock::now();
            linesClearedEffectTimer++;
            squareLineClearEffectSize -= sf::Vector2f(cell.getSize().x / NB_ANIM,
                                                      cell.getSize().y / NB_ANIM);
        }

        // Draw white rectangles
        for (auto &line: linesToDoClearEffect) {
            for (int x = 0; x < COLUMNS; x++) {
                sf::RectangleShape cellClearEffect(squareLineClearEffectSize);
                cellClearEffect.setFillColor(sf::Color::White);
                cellClearEffect.setPosition(0.5 + CELL_SIZE * x + CELL_SIZE / 2 - squareLineClearEffectSize.x / 2,
                                            0.5 + CELL_SIZE * line + CELL_SIZE / 2 - squareLineClearEffectSize.y / 2);
                window.draw(cellClearEffect);
            }
        }

        // Once the animation is finished, we remove the line from the list to do the animation
        if (linesClearedEffectTimer >= NB_ANIM) {
            linesToDoClearEffect.clear();
            squareLineClearEffectSize = cell.getSize();
            linesClearedEffectTimer = 0;
        }
    }

    // Refresh screen
    window.display();

    //Increment FPS
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
