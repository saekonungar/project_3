#ifndef __SCORE_DISPLAY__
#define __SCORE_DISPLAY__

#include "ViewObject.h"

#define SCORE_STRING_MENU "High Score:"
#define SCORE_STRING_LT "Score:"

class ScoreDisplay : public df::ViewObject {
	int level;
	bool in_menu;
	bool showing; //to hide/show on level menu
public:
	ScoreDisplay(int new_level, bool in_menu);
	void show();
	void hide();
	int draw() override;
};

#endif