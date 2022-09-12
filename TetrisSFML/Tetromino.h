#ifndef DEF_TETROMINO
#define DEF_TETROMINO

#include <SFML/Graphics.hpp>
#include <vector>
#include "global.h"

class Tetromino {

protected:
    TetrominoData data;

public:
    Tetromino(const char &name);

    static Tetromino getRandomTetromino();

public:
    bool moveDown(const std::vector<std::vector<TetrisTile>> &matrix);

    bool hardMoveDown(const int &rows);

    void moveLeft(const std::vector<std::vector<TetrisTile>> &matrix);

    void moveRight(const std::vector<std::vector<TetrisTile>> &matrix);

    void rotateClockwise(const std::vector<std::vector<TetrisTile>> &matrix);

    void rotateCounterClockwise(const std::vector<std::vector<TetrisTile>> &matrix);

public:
    [[nodiscard]] std::vector<sf::Vector2f> getTiles() const;

    [[nodiscard]] sf::Color getColor() const;
};

#endif // DEF_TETROMINO
