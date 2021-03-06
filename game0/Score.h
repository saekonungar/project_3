#ifndef __SCORE__
#define __SCORE__

#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
class Score {
    private:
        static bool playing;
        static int timer;
        static int score;
        static int level;
        static std::string strTemp;
        static void setHighScore(int lvl, int score);
    public:
        static int getHighScore(int lvl);
        static int getLargestLevel();
        static void startScore(int current_level);
        static int getScore();
        static void handleTimer();
        static void onWin(int level);
};
#endif 