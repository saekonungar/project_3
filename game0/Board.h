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
	df::ObjectList empty_spaces;
	df::ObjectList filled_spaces;
	Train* train;//may not need this stored here
public:
	Board(const char* filename);
	int eventHandler(const df::Event* p_e) override;
};

#endif