#include "Level.h"
#include "Event.h"
#include "Vector.h"
#include "DisplayManager.h"
#include "WorldManager.h"
#include "EventKeyboard.h"
#include "LogManager.h"
#include "EventWin.h"
#include "EventStep.h"
#include "LevelTransition.h"
#include "Score.h"
#include <string>
using namespace std;

/*LEVEL (manages board in level)
Displays level numbers to be selected
Also handles creating a new board
When the level is being played, it becomes a display int the corner
On a win event, it marks itself for delete
If another level is selected, it is deleted*/

Level::Level(int level_number) {
	//set up attributes
	level_num = level_number;
	game_started = false;
	selected = false;
	if (level_num == 1) selected = true;

	//set up view
	setValue(level_num);
	setViewString(LEVEL_STRING);
	if (selected) setColor(df::YELLOW);
	else setColor(df::BLUE);

	//set up position
	df::Vector v(DM.getHorizontal() / 2, DM.getVertical() / 2);
	v.setX(v.getX() + (LEVEL_SPACE * (level_number - 1)));
	setPosition(v);

	//events
	registerInterest(WIN_EVENT);
	registerInterest(df::STEP_EVENT);

	//create score display
	sd = new ScoreDisplay(level_num, true);
	if (selected) sd->show();
}

int Level::eventHandler(const df::Event* p_e) {
	if (p_e->getType() == WIN_EVENT) {
		LM.writeLog("win event registered - level");
		Score::onWin(level_num);
		new LevelTransition(level_num);

		//delete this and associated objects
		WM.markForDelete(board);
		WM.markForDelete(sd);
		WM.markForDelete(this);
		return 1;
	}
	if (p_e->getType() == df::STEP_EVENT) {
		Score::handleTimer();
		return 1;
	}
	return 0;
}

void Level::scrollLeft() {
	df::Vector v(getPosition().getX(), getPosition().getY());
	v.setX(v.getX() + LEVEL_SPACE);
	setPosition(v);
	//assume it has been deselected
	selected = false;
	setColor(df::BLUE);
	sd->hide();
}

void Level::scrollRight() {
	LM.writeLog("scroll right");
	df::Vector v(getPosition().getX(), getPosition().getY());
	v.setX(v.getX() - LEVEL_SPACE);
	setPosition(v);
	//assume it has been deselected
	selected = false;
	setColor(df::BLUE);
	sd->hide();
}

void Level::select() {
	selected = true;
	setColor(df::YELLOW);
	sd->show();
}

//start up the level!
void Level::launch() {
	string board_title = "boards/board_" + to_string(level_num) + ".txt";
	board = new Board(board_title.c_str());
	game_started = true;
	Score::startScore(level_num);
	sd->hide();
}

int Level::draw() {
	if (!game_started) return ViewObject::draw();
	return 0;
}