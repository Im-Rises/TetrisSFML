#ifndef GLOBAL_H
#define GLOBAL_H

#include <SFML/Graphics.hpp>

#define PROJECT_NAME "Tetris"

#define BACKGROUND_COLOR sf::Color(0, 50, 120)

#define INIT_LEVEL 10
#define MAX_LEVEL 30
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

const std::map<char, TetrominoData> tetrominosMap = {
        {'I', {
                      {{-1, 0}, {-2, 0}, {0, 0}, {1, 0}},
                      sf::Color::Cyan
              }},
        {'J', {
                      {{-2, 0}, {-1, 0}, {0, 0}, {0, 1}},
                      sf::Color::Blue
              }},
        {'L', {
                      {{-2, 0}, {-1, 0}, {0, 0}, {-2, 1}},
                      sf::Color(255, 165, 0)
              }},
        {'O', {
                      {{-1, 0}, {0, 0}, {-1, 1}, {0, 1}},
                      sf::Color::Yellow
              }},
        {'S', {
                      {{-2, 1}, {-1, 1}, {-1, 0}, {0, 0}},
                      sf::Color::Green
              }},
        {'T', {
                      {{-2, 1}, {-1, 1}, {0, 1}, {-1, 0}},
                      sf::Color(128, 0, 128)
              }},
        {'Z', {
                      {{-2, 0}, {-1, 0}, {-1, 1}, {0, 1}},
                      sf::Color::Red
              }}
};

#endif //GLOBAL_H
