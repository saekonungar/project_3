#ifndef __SCORE__
#define __SCORE__

#include "ViewObject.h"

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
class Score : public df::ViewObject {
    private:
        int level;
        bool playing;
        int timer;
        void setHighScore(int lvl, int score);
    public:
        Score();
        int getHighScore(int lvl);
        int getLargestLevel();
        int eventHandler(const df::Event *p_e) override;
        int score;
        void setState(bool state);
        int getScore();
        int draw() override;
        
};
#endif 