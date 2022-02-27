#ifndef __TRAIN__
#define __TRAIN__

#include "Object.h"
#include "Vector.h"
#include "Space.h"
#include "EventKeyboard.h"
#include "Board.h"

#define MAX_BOARD_SIZE 100

class Train : public df::Object {
private:
	Space* train_space; //space the train is currently on
	Board* train_board;
	Direction facing; //may be unneeded attribute
	void kbd(const df::EventKeyboard* p_k_e);
	void move(Direction where);
	Space* p_train_path[MAX_BOARD_SIZE];
	int spaces_filled;
public:
	Train(Space* on_space, Board* on_board);
	int eventHandler(const df::Event* p_e) override;
};

#endif