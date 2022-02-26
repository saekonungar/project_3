#include "Train.h"
#include "LogManager.h"

Train::Train(Space* on_space) {
	setType("Train");
	setSprite("train_up_n");
	setAltitude(3);
	train_space = on_space;
	setPosition(on_space->getPosition());
	registerInterest(df::KEYBOARD_EVENT);

	//keep track of traced path
	spaces_filled = 1;
	p_train_path[0] = train_space;
}


//handle move event:
//move to given space (stored in event)
//update facing and sprite
int Train::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::KEYBOARD_EVENT) {
		const df::EventKeyboard* p_keyboard_event = dynamic_cast <const df::EventKeyboard*> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}
	return 0;
}

void Train::kbd(const df::EventKeyboard* p_k_e) {
	switch (p_k_e->getKey()) {
	case df::Keyboard::W: //up
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED)
			move(Direction::UP);
		break;
	case df::Keyboard::S: //down
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED)
			move(Direction::DOWN);
		break;
	case df::Keyboard::A: //left
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED)
			move(Direction::LEFT);
		break;
	case df::Keyboard::D: //right
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED)
			move(Direction::RIGHT);
		break;
	}
}

void Train::move(Direction where) {
	bool move = false;
	train_space->isMarked();
	//check if the intended move direction is a valid space to move
	if (train_space->getNeighbor(where) != NULL && !train_space->getNeighbor(where)->isMarked()) {
		//update current space
		if (spaces_filled == 1) {//if its the first space,
			train_space->markSpace(UP, where);
		}
		train_space->markSpace(p_train_path[spaces_filled-1], train_space->getNeighbor(where));
		train_space = train_space->getNeighbor(where);
		p_train_path[spaces_filled] = train_space;
		spaces_filled++;

		//physically move train
		setPosition(train_space->getPosition());
		switch (where) {
		case (UP):
			setSprite("train_up_n");
			break;
		case (DOWN):
			setSprite("train_down_n");
			break;
		case (LEFT):
			setSprite("train_left_n");
			break;
		case (RIGHT):
			setSprite("train_right_n");
			break;
		}
	}
}