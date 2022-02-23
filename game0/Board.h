#ifndef __BOARD__
#define __BOARD__

#include "Object.h"
#include "Space.h"
#include "ObjectList.h"
#include "ObjectListIterator.h"

#define MAX_BOARD_SIZE 100

class Board : public df::Object {
private:
	bool board_loaded;
	df::ObjectList empty_spaces;
	df::ObjectList filled_spaces;
	Space* p_train_path[MAX_BOARD_SIZE];
public:
	Board(const char* filename);
	int eventHandler(const df::Event* p_e) override;
};

#endif