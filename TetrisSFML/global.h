#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.hpp>

#define BACKGROUND_COLOR sf::Color(0, 50, 120)

#define INIT_LEVEL 10
#define MAX_LEVEL 20

#define INIT_TIME_FALL 1000 // Intial time at level 1 for a tetromino to fall in ms
#define SOFT_DROP_DOWN_TIME_FALL 0.2 // Time in seconds for a tetromino to fall when the soft drop down key is pressed

const std::string PROJECT_NAME = "Tetris";

const unsigned char CELL_SIZE = 8;
const unsigned char COLUMNS = 10;
const unsigned char ROWS = 20;
const unsigned char SCREEN_SIZE = 4;

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
