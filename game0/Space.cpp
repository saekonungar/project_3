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

Space::Space(df::Vector position) {
	setType("Space");
	setSprite("space");
	setPosition(position);
	isStart = false;
	marked = false;
	registerInterest(df::STEP_EVENT);
	up = NULL;
	down = NULL;
	left = NULL;
	right = NULL;
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
		return 1;
	}
	return 0;
}

bool Space::isMarked() const {
	return marked;
}

void Space::setAsStart() {
	isStart = true;
}

void Space::markSpace(Space* prev, Space* next) {
	marked = true;
	//update sprite

	//vertical
	if ((prev == down && next == up) || (prev == up && next == down) ||
		(prev == NULL && next == up) || (prev == NULL && next == down))
		setSprite("tracks_vertical");

	//horizontal
	if ((prev == right && next == left) || (prev == left && next == right) ||
		(prev == NULL && next == left) || (prev == NULL && next == right))
		setSprite("tracks_horizontal");

	//bottom left corner
	if ((prev == up && next == right) || (prev == right && next == up))
		setSprite("tracks_corner1");

	//bottom right corner
	if ((prev == up && next == left) || (prev == left && next == up))
		setSprite("tracks_corner2");

	//top right corner
	if ((prev == down && next == left) || (prev == left && next == down))
		setSprite("tracks_corner3");

	//top left corner
	if ((prev == down && next == right) || (prev == right && next == down))
		setSprite("tracks_corner4");
}

void Space::eraseSpace() {
	marked = false;
	setSprite("space");
}
