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

    Tetromino fallingTetromino = Tetromino::getRandomTetromino();
    Tetromino nextTetromino = Tetromino::getRandomTetromino();

    std::vector<std::vector<TetrisTile>> matrix;

public:
    Tetris();
    //	~Tetris();

    void start();

    void handleEvents();

    int updateGame(int cycleCounter);

    void refreshScreen();

    void sleepTime(int &cyclesCounter, std::chrono::steady_clock::time_point &previousTime);
};

#endif // DEF_TETRIS
