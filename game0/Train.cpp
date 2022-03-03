#include "Train.h"
#include "LogManager.h"
#include "WorldManager.h"
#include "GameManager.h"
#include "EventWin.h"
#include "EventStep.h"

Train::Train(Space* on_space) {
	setType("Train");
	setSprite("train_up_n");
	setAltitude(3);
	setPosition(on_space->getPosition());

	//attributes
	train_space = on_space;
	spaces_to_fill = 0;
	level_started = false;
	level_completed = false;
	facing = Direction::UP;
	timer = 0;

	//events
	registerInterest(df::KEYBOARD_EVENT);
	registerInterest(df::STEP_EVENT);

	//keep track of traced path
	spaces_filled = 1;
	p_train_path[0] = train_space;
}

void Train::setNumSpaces(int spaces) {
	spaces_to_fill = spaces;
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
	if (p_e->getType() == df::STEP_EVENT) {
		step();
		return 1;
	}
	return 0;
}

void Train::kbd(const df::EventKeyboard* p_k_e) {
	//handle first move (enter key is still pressed)
	if (!level_started && p_k_e->getKey() != df::Keyboard::RETURN && p_k_e->getKey() != df::Keyboard::SPACE) {
		level_started = true;
		timer = 0;
	}
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
	case df::Keyboard::Q: //end game
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED)
			GM.setGameOver();
		break;
	}
}

void Train::move(Direction where) {
	bool move = false;
	train_space->isMarked();
	//check if the intended move direction is a valid space to move forwards
	if (train_space->getNeighbor(where) != NULL && !train_space->getNeighbor(where)->isMarked()) {
		//update current space
		if (spaces_filled == 1) {//if its the first space,
			train_space->markSpace(NULL, train_space->getNeighbor(where));
		}
		else {
			train_space->markSpace(p_train_path[spaces_filled - 2], train_space->getNeighbor(where));
		}
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

		//after a move forward, check for win
		if (spaces_filled == spaces_to_fill) {
			train_space->markSpace(p_train_path[spaces_filled-1], NULL);
			level_completed = true;
			//EventWin win;
			//WM.onEvent(&win);
		}

	}
	//see if the player is trying to move backwards
	else if (spaces_filled != 1 &&
		train_space->getNeighbor(where) == p_train_path[spaces_filled-2]){

		//update info
		p_train_path[spaces_filled-1]->eraseSpace();
		spaces_filled--;
		train_space = train_space->getNeighbor(where);

		//physically move train
		setPosition(train_space->getPosition());
		switch (where) {
		case (UP):
			setSprite("train_down_n");
			break;
		case (DOWN):
			setSprite("train_up_n");
			break;
		case (LEFT):
			setSprite("train_right_n");
			break;
		case (RIGHT):
			setSprite("train_left_n");
			break;
		}
	}

}

//step handler
//at start of game: train rotation (1 second for each rotation)
//at end of game: timer until win event created (1 second)
void Train::step() {
	//start of game
	if (!level_started) {
		if (timer == 15) {
			switch (facing) {
			case (UP):
				setSprite("train_right_n");
				facing = Direction::RIGHT;
				break;
			case (RIGHT):
				setSprite("train_down_n");
				facing = Direction::DOWN;
				break;
			case (DOWN):
				setSprite("train_left_n");
				facing = Direction::LEFT;
				break;
			case (LEFT):
				setSprite("train_up_n");
				facing = Direction::UP;
				break;
			}
			timer = 0;
		}
		else {
			timer++;
		}
	}
	//end of game
	else if (level_completed) {
		if (timer == 15) {
			EventWin win;
			WM.onEvent(&win);
		}
		timer++;
	}
}