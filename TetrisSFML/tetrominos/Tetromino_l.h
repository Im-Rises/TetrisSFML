#ifndef DEF_TETROMINO_L
#define DEF_TETROMINO_L

#include "../Tetromino.h"

class Tetromino_l : public Tetromino {
public:
	Tetromino_l();

	void reset() override;

	void rotate() override;
};


#endif // DEF_TETROMINO_L
