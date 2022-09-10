#ifndef DEF_TETROMINO
#define DEF_TETROMINO

#include <SFML/Graphics.hpp>
#include <vector>

class Tetromino {

public:
    std::vector<sf::Vector2f> tiles;
    sf::Color color;

public:
    Tetromino();

    virtual void reset() = 0;

    bool moveDown(const int &rows);

    virtual bool hardMoveDown(const int &rows);

    virtual bool moveLeft(const int &columns);

    virtual bool moveRight(const int &columns);

    virtual void rotate() = 0;

    std::vector<sf::Vector2f> getTiles() const;

    sf::Color getColor() const;
};

#endif // DEF_TETROMINO
