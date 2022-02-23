#include "Space.h"
#include "Vector.h"
#include "EventStep.h"
#include "LogManager.h"

//space design
//each space is a node that connects to adjacent spaces
//spaces are created based on inputted strings
//there is a single starting node
//spaces are also put on an an objectlist so as to be able to iterate through them
//this list will be handled in the Board class
//2 lists: total spaces, and filled spaces
//whether a space is empty or filled is tracked in this class, and sprites are handled

Space::Space() {
	setType("Space");
	setSprite("space");
	df::Vector v(10, 10);
	setPosition(v);
	isStart = false;
	registerInterest(df::STEP_EVENT);
}

void Space::setNeighbor(Direction which, Space* new_node) {
	switch (which) {
	case UP:
		up = new_node;
		break;
	case DOWN:
		down = new_node;
		break;
	case LEFT:
		left = new_node;
		break;
	case RIGHT:
		right = new_node;
		break;
	}
}

Space* Space::getNeighbor(Direction which) {
	switch (which) {
	case UP:
		return up;
		break;
	case DOWN:
		return down;
		break;
	case LEFT:
		return left;
		break;
	case RIGHT:
		return right;
		break;
	}
	return NULL;
}

//Move event:
//check and see which direction the train is moving in
//access the path of the train to figure out which sprite to use and which sprite to change
int Space::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::STEP_EVENT) {
		step();
		return 1;
	}
	return 0;
}

void Space::step() {
	//on each step
}