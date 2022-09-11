#ifndef DEF_TETROMINO_I
#define DEF_TETROMINO_I

#include "../Tetromino.h"

class Tetromino_i : public Tetromino {
public:
	Tetromino_i();

	void reset() override;

	void rotate() override;
};


#endif // DEF_TETROMINO_I
