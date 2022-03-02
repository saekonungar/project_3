#ifndef __LEVEL_TRANSITION__
#define __LEVEL_TRANSITIONprev__

#include "Object.h"
#include "Board.h"

#define LEVEL_STRING "Level"
#define LEVEL_SPACE 15

class LevelTransition : public df::Object {
private:
	int prev_level;
	void kbd(const df::EventKeyboard* p_k_e);
public:
	LevelTransition(int previous);
	int eventHandler(const df::Event* p_e) override;
};

#endif