#ifndef __SCORE__
#define __SCORE__
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
class Score : public df::ViewObject {
    private:
        void start();
        int level;
    public:
        Score(std::string type, std::string sprite);
        int score;
        int timer;
        int eventHandler(const df::Event *p_e) override;
};
#endif 