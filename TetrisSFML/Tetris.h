#ifndef DEF_TETRIS
#define DEF_TETRIS


#define PROJECT_NAME "Tetris"

const unsigned char CELL_SIZE = 8;
const unsigned char COLUMNS = 10;
const unsigned char ROWS = 20;
const unsigned char SCREEN_SIZE = 4;

const unsigned short FRAME_DURATION = 16;

class Tetris {
private:
public:
	Tetris();
	//	~Tetris();

	void start();
};

#endif // DEF_TETRIS
