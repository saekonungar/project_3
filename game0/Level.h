#ifndef __LEVEL__
#define __LEVEL__

#include "ViewObject.h"
#include "Board.h"

#define LEVEL_STRING "Level"
#define LEVEL_SPACE 15

class Level : public df::ViewObject {
private:
	bool game_started;
	bool selected;
	Board* board;
	int level_num;
public:
	Level(int level_number);
	int eventHandler(const df::Event* p_e) override;
	int draw() override;
	void scrollRight();
	void scrollLeft();
	void select();
	void launch();
};

#endif
