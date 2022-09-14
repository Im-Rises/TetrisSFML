#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.hpp>

const sf::Color BACKGROUND_COLOR(0, 50, 120);

const int INIT_LEVEL = 1; // Initial difficulty level
const int MAX_LEVEL = 10; // Max difficulty level is 10

const int NB_LINES_DIFFICULTY_CHANGE = 10; // Number of lines cleared to increase the difficulty level by 1

const int INIT_TIME_FALL = 2000; // Intial time at level 1 for a tetromino to fall in ms
const int SOFT_DROP_TIME_DIVIDER = 4; // Drop time is divided by this value when soft drop is activated

const std::string PROJECT_NAME = "Tetris";

const int CELL_SIZE = 8;
const int COLUMNS = 10;
const int ROWS = 20;
const int SCREEN_SIZE = 4;

const std::string FONT_PATH = "arial.ttf";

struct TetrisTile {
    bool state = false;
    sf::Color color = BACKGROUND_COLOR;
};

struct TetrominoData {
    std::vector<sf::Vector2f> tiles;
    sf::Color color;
    std::string name;
    bool fullyRotable;
};

#endif //GLOBAL_H
