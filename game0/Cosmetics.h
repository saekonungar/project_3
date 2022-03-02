#ifndef __COSMETICS__
#define __COSMETICS__

#include "Object.h"

enum C_Sprite {
	TRACK_LINE,
};


class Cosmetics : public df::Object {

private:
	C_Sprite c_type;
public:
	Cosmetics(C_Sprite new_c_type);
};

#endif