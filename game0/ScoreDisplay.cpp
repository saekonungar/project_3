#include "ScoreDisplay.h"
#include "Score.h"
#include "DisplayManager.h"

/*
Score Display is created and deleted by the Level and LevelTransition
It shows up in two places: in the level selection
and in the level transition after a game is won*/

ScoreDisplay::ScoreDisplay(int new_level, bool in_menu) {
	//set up attributes
	level = new_level;
	setType("ScoreDisplay");
	if (in_menu) showing = false;
	else showing = true;

	//set up position
	if (in_menu) {
		df::Vector v(DM.getHorizontal() / 2, (DM.getVertical() / 2) + 3);
		setPosition(v);
	}
	else {
		df::Vector v(DM.getHorizontal() / 2, (DM.getVertical() / 2) - 1);
		setPosition(v);
	}

	//set up view
	setValue(Score::getHighScore(level));
	if (in_menu) setViewString(SCORE_STRING_MENU);
	else setViewString(SCORE_STRING_LT);
	setColor(df::YELLOW);
}

void ScoreDisplay::show() {
	showing = true;
}

void ScoreDisplay::hide() {
	showing = false;
}

int ScoreDisplay::draw() {
	if (showing) return df::ViewObject::draw();
	return 1;
}