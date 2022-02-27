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
	Train* train;//may not need this stored here
	df::ObjectList empty_spaces;
	df::ObjectList filled_spaces;
public:
	Board(const char* filename);
	int getNumSpaces() const; //return the number of spaces in the board
};

#endif