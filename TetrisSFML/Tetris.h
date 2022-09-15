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
    int lines = 0;
    int fps = 0;
    int softDropValue = 1;

    sf::RenderWindow window;
    sf::RectangleShape cell;
    sf::Event event;

    sf::RenderTexture textureBuffer;

    sf::RectangleShape previewRectangle;
    Tetromino fallingTetromino = Tetromino::getRandomTetromino();
    Tetromino nextTetromino = Tetromino::getRandomTetromino();

    std::vector<std::vector<TetrisTile>> matrix;

    sf::Font font;
    sf::Text linesText;
    sf::Text levelText;

    std::vector<int> linesToDoClearEffect;

public:
    Tetris();
    //	~Tetris();

    void reset();

    void start();

    void handleEvents();

    void updateGame(std::chrono::steady_clock::time_point &previousTime);

    void refreshScreen(std::chrono::steady_clock::time_point &animationPreviousTime);

    void handleFps(std::chrono::steady_clock::time_point &fpsPreviousTime);
};

#endif // DEF_TETRIS
