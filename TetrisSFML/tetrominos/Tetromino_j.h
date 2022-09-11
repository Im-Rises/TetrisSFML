#ifndef DEF_TETROMINO_J
#define DEF_TETROMINO_J

#include "../Tetromino.h"

class Tetromino_j : public Tetromino {
public:
	Tetromino_j();

	void reset() override;

	void rotate() override;
};

#endif // DEF_TETROMINO_J
