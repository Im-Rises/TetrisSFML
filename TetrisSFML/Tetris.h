#ifndef DEF_TETRIS
#define DEF_TETRIS

#include <SFML/Graphics.hpp>
#include <chrono>
#include "Tetromino.h"
#include "global.h"

const unsigned short FRAME_DURATION = 16; // Frame duration in milliseconds

class Tetris {
private:
    int difficultyLevel;
    sf::RenderWindow window;
    sf::RectangleShape cell;
    sf::Event event;

    sf::RectangleShape previewRectangle;
    Tetromino fallingTetromino = Tetromino::getRandomTetromino();
    Tetromino nextTetromino = Tetromino::getRandomTetromino();

    std::vector<std::vector<TetrisTile>> matrix;

    int lines = 0;
    int fps = 0;

    int softDropValue = 1;

    sf::RectangleShape textBackground;
    sf::Font font;
    sf::Text linesText;
    sf::Text levelText;

public:
    Tetris();
    //	~Tetris();

    void reset();

    void start();

    void handleEvents();

    void updateGame(std::chrono::steady_clock::time_point &previousTime);

    void refreshScreen();

    void handleFps(std::chrono::steady_clock::time_point &fpsPreviousTime);
};

#endif // DEF_TETRIS
