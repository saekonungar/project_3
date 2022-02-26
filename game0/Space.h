#ifndef __SPACE__
#define __SPACE__

#include "Object.h"

enum Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT,
};

class Space : public df::Object {

private:
	Space *up;
	Space *down;
	Space *left;
	Space *right;
	bool isStart;
	bool marked;
public:
	Space(df::Vector position);
	int eventHandler(const df::Event* p_e) override;
	void setNeighbor(Direction which, Space *new_node);
	Space* getNeighbor(Direction which);
	bool isMarked() const;
	void setAsStart();
	void markSpace(Space* prev, Space* next);
	void eraseSpace();
};

#endif 