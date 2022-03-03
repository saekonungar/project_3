#ifndef __TRAIN__
#define __TRAIN__

#include "Object.h"
#include "Vector.h"
#include "Space.h"
#include "EventKeyboard.h"

#define MAX_BOARD_SIZE 100

class Train : public df::Object {
private:
	Space* train_space; //space the train is currently on
	Direction facing;
	void kbd(const df::EventKeyboard* p_k_e);
	void move(Direction where);
	Space* p_train_path[MAX_BOARD_SIZE];
	int spaces_filled;
	int spaces_to_fill;
	int timer; //for rotation at start of level
	bool level_started;
	bool level_completed;
	void step(); //for beginning and end of level
public:
	Train(Space* on_space);
	int eventHandler(const df::Event* p_e) override;
	void setNumSpaces(int spaces); //sets spaces_to_fill
};

#endif