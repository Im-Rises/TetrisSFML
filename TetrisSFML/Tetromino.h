#ifndef DEF_TETROMINO
#define DEF_TETROMINO

#include <SFML/Graphics.hpp>
#include <vector>

class Tetromino {

protected:
	std::vector<sf::Vector2f> tiles;

public:
	Tetromino();
	//	~Tetromino();

	virtual void moveDown() = 0;

	virtual void rotate() = 0;
};

#endif // DEF_TETROMINO
