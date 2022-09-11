#ifndef DEF_TETROMINO
#define DEF_TETROMINO

#include <SFML/Graphics.hpp>
#include <vector>
#include "tetrominsmap.h"

class Tetromino {

protected:
    TetrominoData data;

public:
    Tetromino(const char &name);

    void moveDown(const int &rows);

    bool hardMoveDown(const int &rows);

    bool moveLeft(const int &columns);

    bool moveRight(const int &columns);

    void rotate();

    [[nodiscard]] std::vector<sf::Vector2f> getTiles() const;

    [[nodiscard]] sf::Color getColor() const;

    static Tetromino getRandomTetromino();
};

#endif // DEF_TETROMINO
