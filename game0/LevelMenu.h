#ifndef __LEVEL_MENU__
#define __LEVEL_MENU__

#include "Object.h"
#include "Level.h"
#include "EventKeyboard.h"
#include "Cosmetics.h"

#define NUM_OF_LEVELS 3

class LevelMenu : public df::Object{
private:
	int current_level; //holds level number
	Level* all_levels[NUM_OF_LEVELS];
	bool game_started;
	void kbd(const df::EventKeyboard* p_k_e);
	Cosmetics* tracks_accross;
public:
	LevelMenu();
	int eventHandler(const df::Event* p_e) override;
	void scrollForwards(int amount); //for setting up after a level
};

#endif