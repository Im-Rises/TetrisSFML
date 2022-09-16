#ifndef DEF_TETRIS
#define DEF_TETRIS

#include <SFML/Graphics.hpp>
#include <chrono>
#include "Tetromino.h"
#include "global.h"


class Tetris {
private:
    int difficultyLevel;
    int linesCounter = 0;
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
    std::vector<std::vector<TetrisTile>> previousMatrix;

    sf::Font font;
    sf::Text linesText;
    sf::Text bestScoreLinesText;
    sf::Text levelText;

    int linesClearedEffectTimer = 0; // 30 levels of diminution of the square size
    std::vector<int> linesToDoClearEffect; // List of linesCounter to do the clear animation
    sf::Vector2f squareLineClearEffectSize; // Size of the square for the clear effect

    int maxScore = 0;

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
