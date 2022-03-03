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
        static void setHighScore(int lvl, int score);
    public:
        Score();
        static int getHighScore(int lvl);
        static int getLargestLevel();
        int eventHandler(const df::Event *p_e) override;
        int score;
        static void setState(int state);
        
};
#endif 