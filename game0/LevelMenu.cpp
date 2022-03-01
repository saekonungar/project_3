#include "LevelMenu.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include "LogManager.h"

/*
Level Menu is created when player presses P at the start
It creates all of the Level objects that can be used to start a puzzle
NOTE: the level attribute holds the level NUMBER, not its index on the list
*/

LevelMenu::LevelMenu() {
	registerInterest(df::KEYBOARD_EVENT);
	game_started = false;

	setType("LevelMenu");
	setSprite("level_menu");
	df::Vector v(DM.getHorizontal() / 2, 4);
	setPosition(v);

	//set up levels
	for (int i = 0; i < NUM_OF_LEVELS; i++) {
		Level *l = new Level(i+1);
		all_levels[i] = l;
	}
	current_level = 1;
}

int LevelMenu::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::KEYBOARD_EVENT) {
		const df::EventKeyboard* p_keyboard_event = dynamic_cast <const df::EventKeyboard*> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}
	return 0;
}

//scroll through puzzles to choose one
void LevelMenu::kbd(const df::EventKeyboard* p_k_e) {
	switch (p_k_e->getKey()) {
	case df::Keyboard::D: //select next
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED && !game_started)
			if (current_level != NUM_OF_LEVELS) {
				for (int i = 0; i < NUM_OF_LEVELS; i++) {
					all_levels[i]->scrollRight();
				}
				current_level++;
				all_levels[current_level-1]->select();
			}
		break;
	case df::Keyboard::A: //select previous
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED && !game_started)
			if (current_level != 1) {
				for (int i = 0; i < NUM_OF_LEVELS; i++) {
					all_levels[i]->scrollLeft();
				}
				current_level--;
				all_levels[current_level-1]->select();
			}
		break;
	case df::Keyboard::RETURN: //select current level
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED && !game_started) {
			for (int i = 0; i < NUM_OF_LEVELS; i++) {
				if (i == current_level - 1) {
					all_levels[i]->launch();
				}
				else {
					WM.markForDelete(all_levels[i]);
				}
			}
			setSprite("empty");
			game_started = true;
		}
		break;
	}
}