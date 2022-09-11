#ifndef DEF_TETROMINSMAP
#define DEF_TETROMINSMAP

#include <map>
#include <vector>
#include <SFML/Graphics.hpp>

// I thought it was funny ;)

struct TetrominoData {
    std::vector<sf::Vector2f> tiles;
    sf::Color color;
};

const std::map<char, TetrominoData> tetrominosMap = {
        {'I', {
                      {{0, 0}, {1, 0}, {2, 0}, {3, 0}},
                      sf::Color::Cyan
              }},
        {'J', {
                      {{0, 0}, {0, 1}, {1, 1}, {2, 1}},
                      sf::Color::Blue
              }},
        {'L', {
                      {{0, 1}, {1, 1}, {2, 1}, {2, 0}},
                      sf::Color(255, 165, 0)
              }},
        {'O', {
                      {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
                      sf::Color::Yellow
              }},
        {'S', {
                      {{0, 1}, {1, 1}, {1, 0}, {2, 0}},
                      sf::Color::Green
              }},
        {'T', {
                      {{0, 1}, {1, 1}, {2, 1}, {1, 0}},
                      sf::Color(128, 0, 128)
              }},
        {'Z', {
                      {{0, 0}, {1, 0}, {1, 1}, {2, 1}},
                      sf::Color::Red
              }}
};

#endif //DEF_TETROMINSMAP
