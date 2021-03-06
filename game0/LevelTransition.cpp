#include "LevelTransition.h"
#include "Event.h"
#include "EventKeyboard.h"
#include "LevelMenu.h"
#include "Level.h"
#include "WorldManager.h"
#include "DisplayManager.h"
#include "GameManager.h"
#include "LogManager.h"
#include "GameManager.h"
#include "Score.h"
#include <stdio.h>
/*
This is the menu that appears in between levels
the player has the choice to go to the next level
or return to the level menu*/

LevelTransition::LevelTransition(int previous) {
	//set up sprite
	setType("Level_Transition");
	setSprite("level_transition");
	prev_level = previous;
	//set up location
	df::Vector v(DM.getHorizontal() / 2, DM.getVertical() / 2);
	setPosition(v);

	//set up display
	score_display = new ScoreDisplay(prev_level, false);

	//set up for events
	registerInterest(df::KEYBOARD_EVENT);
}

int LevelTransition::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == df::KEYBOARD_EVENT) {
		const df::EventKeyboard* p_keyboard_event = dynamic_cast <const df::EventKeyboard*> (p_e);
		kbd(p_keyboard_event);
		return 1;
	}
	return 0;
}

void LevelTransition::kbd(const df::EventKeyboard* p_k_e) {
	switch (p_k_e->getKey()) {
	case df::Keyboard::SPACE: //next level
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED)
			if (prev_level != NUM_OF_LEVELS) {
				Level *l = new Level(prev_level+1);
				l->launch();
				WM.markForDelete(score_display);
				WM.markForDelete(this);
			}
		break;
	case df::Keyboard::RETURN: //down
		if (p_k_e->getKeyboardAction() == df::KEY_PRESSED) {
			LevelMenu *lm = new LevelMenu;
			lm->scrollForwards(prev_level - 1);
			WM.markForDelete(score_display);
			WM.markForDelete(this);
		}
		break;
	case df::Keyboard::Q: //q
		GM.setGameOver();
		break;
	}
}