#ifndef DEF_TETRIS
#define DEF_TETRIS

#include <SFML/Graphics.hpp>
#include <chrono>
#include "Tetromino.h"

#define PROJECT_NAME "Tetris"
#define BACKGROUND_COLOR sf::Color(0, 50, 120)

#define INIT_LEVEL 20
#define MAX_LEVEL 20
#define INIT_TIME_FALL 120 // Intial time at level 1 for a tetromino to fall in seconds

const unsigned char CELL_SIZE = 8;
const unsigned char COLUMNS = 10;
const unsigned char ROWS = 20;
const unsigned char SCREEN_SIZE = 4;

const unsigned short FRAME_DURATION = 16;


class Tetris {
private:
    int difficultyLevel;
    sf::RenderWindow window;
    sf::RectangleShape cell;
    sf::Event event;

    Tetromino fallingTetromino = Tetromino::getRandomTetromino();
//    std::unique_ptr<Tetromino> nextTetromino = Tetromino::getRandomTetromino();

    struct {
        bool state = false;
        sf::Color color = BACKGROUND_COLOR;
    } matrix[COLUMNS][ROWS];

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
