#include "Cosmetics.h"
#include "DisplayManager.h"

/*
for displaying sprites with no actual function in game purposes
Current options:
- TRACK_LINE : line across the screen in level selection
May add in future:
- BG_TERRAIN: some texture for the background of puzzles
- TRAIN: a train circling the start menu
*/

Cosmetics::Cosmetics(C_Sprite new_c_type) {
	c_type = new_c_type;
	setType("Cosmetics");
	switch (c_type) {
	case TRACK_LINE:
		setSprite("tracks_across");
		df::Vector v(DM.getHorizontal() / 2, DM.getVertical() / 2);
		setPosition(v);
		setAltitude(1);
		break;
	}
}