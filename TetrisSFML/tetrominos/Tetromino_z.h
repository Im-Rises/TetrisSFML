#ifndef DEF_TETROMINO_Z
#define DEF_TETROMINO_Z

#include "../Tetromino.h"

class Tetromino_z : public Tetromino {
public:
    Tetromino_z();

    void reset() override;

    void rotate() override;
};


#endif // DEF_TETROMINO_Z
