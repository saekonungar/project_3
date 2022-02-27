#ifndef __BOARD__
#define __BOARD__

#include "Object.h"
#include "Space.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"
#include "Train.h"

class Board : public df::Object {
private:
	bool board_loaded;
	int board_rows;
	int board_columns;
	int num_of_spaces;
	df::ObjectList all_spaces;
	Train* train;
public:
	Board(const char* filename);
	~Board();
	int getNumSpaces() const; //return the number of spaces in the board
};

#endif