#ifndef DEF_TETROMINO
#define DEF_TETROMINO

#include <SFML/Graphics.hpp>
#include <vector>
#include "global.h"


// Tetrominos are defined by their tiles and their color
// The tiles are defined by their position relative to the center of the tetromino
const std::map<char, TetrominoData> tetrominosMap = {
        {'I', {
                      {{-1, 0}, {0, 0}, {1,  0},  {2,  0}},
                      sf::Color::Cyan,
                      "I",
                      false
              }},
        {'J', {
                      {{-1, 0}, {0, 0}, {1,  0},  {1,  1}},
                      sf::Color::Blue,
                      "J",
                      true
              }},
        {'L', {
                      {{-1, 0}, {0, 0}, {1,  0},  {-1, 1}},
                      sf::Color(255, 165, 0),
                      "L",
                      true
              }},
        {'O', {
                      {{0,  0}, {1, 0}, {0,  -1}, {1,  -1}},
                      sf::Color::Yellow,
                      "O",
                      true
              }},
        {'S', {
                      {{0,  0}, {1, 0}, {-1, 1},  {0,  1}},
                      sf::Color::Green,
                      "S",
                      false
              }},
        {'T', {
                      {{-1, 0}, {0, 0}, {1,  0},  {0,  -1}},
                      sf::Color(157, 50, 168),
                      "T",
                      true
              }},
        {'Z', {
                      {{-1, 0}, {0, 0}, {0,  1},  {1,  1}},
                      sf::Color::Red,
                      "Z",
                      false
              }}
};


class Tetromino {

private:

    TetrominoData data;

    int cordonateX;
    int cordonateY;

    bool rotated = false;

public:
    Tetromino(const char &name);

    static Tetromino getRandomTetromino();

public:
    bool moveDown(const std::vector<std::vector<TetrisTile>> &matrix);

    bool hardMoveDown(const std::vector<std::vector<TetrisTile>> &matrix);

    void moveLeft(const std::vector<std::vector<TetrisTile>> &matrix);

    void moveRight(const std::vector<std::vector<TetrisTile>> &matrix);

public:
    void rotateClockwise(const std::vector<std::vector<TetrisTile>> &matrix);

    void rotateCounterClockwise(const std::vector<std::vector<TetrisTile>> &matrix);

private:
    void rotateTetrominoHandler(const std::vector<std::vector<TetrisTile>> &matrix, bool counterClockwise);

    void rotate(const std::vector<std::vector<TetrisTile>> &matrix, bool counterClockwise);

public:
    Tetromino getShadowTetromino(const std::vector<std::vector<TetrisTile>> &matrix);

public:
    [[nodiscard]] std::vector<sf::Vector2f> getTilesPosition() const;

    [[nodiscard]] std::vector<sf::Vector2f> getTiles() const;

    [[nodiscard]] std::vector<sf::Vector2f> getTilesXReversed() const;

    [[nodiscard]] sf::Color getColor() const;

    [[nodiscard]] std::string getName() const;
};

#endif // DEF_TETROMINO
