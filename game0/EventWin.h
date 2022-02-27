#ifndef __EVENT_WIN__
#define __EVENT_WIN__

#include "Event.h"

const std::string WIN_EVENT = "win";

class EventWin : public df::Event {
public:
	EventWin();
};

#endif