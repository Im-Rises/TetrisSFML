#ifndef DEF_TETROMINO_S
#define DEF_TETROMINO_S

#include "../Tetromino.h"

class Tetromino_s : public Tetromino {
public:
	Tetromino_s();

	void reset() override;

	void rotate() override;
};

#endif // DEF_TETROMINO_S
