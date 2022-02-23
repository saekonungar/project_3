#ifndef __SPACE__
#define __SPACE__

#include "Object.h"

class Space : public df::Object {

enum Direction{
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

private:
	Space *up;
	Space *down;
	Space *left;
	Space *right;
	bool isStart;
	void step();
public:
	Space();
	int eventHandler(const df::Event* p_e) override;
	void setNeighbor(Direction which, Space *new_node);
	Space* getNeighbor(Direction which);
};

#endif 