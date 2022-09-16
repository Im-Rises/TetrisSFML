#ifndef DEF_TETROMINO
#define DEF_TETROMINO

#include <SFML/Graphics.hpp>
#include <vector>
#include "global.h"


class Tetromino {

private:

    TetrominoData data;

    int cordonateX;
    int cordonateY;

    bool rotated = false;

    // Tetrominos are defined by their tiles and their color
    // The tiles are defined by their position relative to the center of the tetromino
    static const std::map<char, TetrominoData> tetrominosMap;

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
