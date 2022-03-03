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
        static void setHighScore(int lvl, int score);
    public:
        Score();
        static int getHighScore(int lvl);
        static int getLargestLevel();
        int eventHandler(const df::Event *p_e) override;
        int score;
        static void setState(bool state);
        static int getScore();
        int draw() override;
        
};
#endif 