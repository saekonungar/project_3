#include "EventWin.h"
#include "LogManager.h"

EventWin::EventWin() {
	setType(WIN_EVENT);
	LM.writeLog("win event created");
}