#include "Train.h"
#include "EventKeyboard.h"

Train::Train(Space* on_space) {
	setType("Train");
	setSprite("train_up_n");
	setAltitude(3);
	train_space = on_space;
	setPosition(on_space->getPosition());
	registerInterest(df::KEYBOARD_EVENT);
}


//handle move event:
//move to given space (stored in event)
//update facing and sprite
int Train::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == KEYBOARD_EVENT) {
		return 1;
	}
	return 0;
}

void Train::kbd(const df::EventKeyboard* p_k_e) {
	switch (p_k_e->getKey()) {
	case df::Keyboard::W: //up
		if (p_keyboard_event->getKeyboardAction() == df::KEY_DOWN)
			move(Direction::UP);
		break;
	case df::Keyboard::S: //down
		if (p_keyboard_event->getKeyboardAction() == df::KEY_DOWN)
			move(Direction::DOWN);
		break;
	case df::Keyboard::A: //left
		if (p_keyboard_event->getKeyboardAction() == df::KEY_DOWN)
			move(Direction::LEFT);
		break;
	case df::Keyboard::D: //right
		if (p_keyboard_event->getKeyboardAction() == df::KEY_DOWN)
			move(Direction::RIGHT);
		break;
	}
}

void Train::move(Direction where) {
	bool move = false;
	if (train_space->getNeighbor(where) != NULL && !train_space->getNeighbor(where)->isMarked()) {
		train_space->markSpace();
		train_space = train_space->getNeighbor(where);

	}
}