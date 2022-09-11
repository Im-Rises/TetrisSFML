#ifndef DEF_TETROMINO_T
#define DEF_TETROMINO_T

#include "../Tetromino.h"

class Tetromino_t : public Tetromino {
public:
	Tetromino_t();

	void reset() override;

	void rotate() override;
};


#endif // DEF_TETROMINO_T
