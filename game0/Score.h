#ifndef __SCORE__
#define __SCORE__
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
class Score {
    private:
        int level;
        int playing;
        int timer;
        void setHighScore(int lvl, int score);
    public:
        Score();
        int getHighScore(int lvl);
        int getLargestLevel();
        int eventHandler(const df::Event *p_e) override;
        int score;
        void setState(int state);
        
};
#endif 