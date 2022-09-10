#ifndef TETROMINO_CUBE
#define TETROMINO_CUBE

#include "../Tetromino.h"

class Tetromino_o : public Tetromino {
public:
	Tetromino_o();

	void moveDown() override;

	void rotate() override;
};

#endif // TETROMINO_CUBE