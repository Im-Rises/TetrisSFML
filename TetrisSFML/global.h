#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.hpp>

#define PROJECT_NAME "Tetris"

#define BACKGROUND_COLOR sf::Color(0, 50, 120)

#define INIT_LEVEL 10
#define MAX_LEVEL 20
#define INIT_TIME_FALL 120 // Intial time at level 1 for a tetromino to fall in seconds

const unsigned char CELL_SIZE = 8;
const unsigned char COLUMNS = 10;
const unsigned char ROWS = 20;
const unsigned char SCREEN_SIZE = 4;

struct TetrisTile {
    bool state = false;
    sf::Color color = BACKGROUND_COLOR;
};


// I thought it was funny ;)
struct TetrominoData {
    std::vector<sf::Vector2f> tiles;
    sf::Color color;
};

// Tetrominos are defined by their tiles and their color
// The tiles are defined by their position relative to the center of the tetromino
const std::map<char, TetrominoData> tetrominosMap = {
        {'I', {
                      {{-2, 0}, {-1, 0}, {0,  0},  {1,  0}},
                      sf::Color::Cyan
              }},
        {'J', {
                      {{-1, 0}, {0,  0}, {1,  0},  {1,  1}},
                      sf::Color::Blue
              }},
        {'L', {
                      {{-1, 0}, {0,  0}, {1,  0},  {-1, 1}},
                      sf::Color(255, 165, 0)
              }},
        {'O', {
                      {{-1, 0}, {0,  0}, {-1, 1},  {0,  1}},
                      sf::Color::Yellow
              }},
        {'S', {
                      {{0,  0}, {1,  0}, {-1, -1}, {0,  -1}},
                      sf::Color::Green
              }},
        {'T', {
                      {{-1, 0}, {0,  0}, {1,  0},  {0,  1}},
                      sf::Color(128, 0, 128)
              }},
        {'Z', {
                      {{-1, 0}, {0,  0}, {0,  1},  {1,  1}},
                      sf::Color::Red
              }}
};

#endif //GLOBAL_H
