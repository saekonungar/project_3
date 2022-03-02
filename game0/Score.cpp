// This manages the score, the level timer (which the score is derived from), and the saves (because this is always persistent);
#include "Score.h"
#include "LogManager.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Event.h"
#include "EventStep.h"
#include "EventWin.h"

Score::Score(){
    registerInterest(WIN_EVENT);
    registerInterest(df::STEP_EVENT);
    setViewString(score);
}
int Score::getLargestLevel(){
    std::ifstream input("derailed.save");
    std::string line;
    while( std::getline( input, line ) ) {
        level = stoi(line.substr(0, line.find(","))); 
    }
    return level;
}

int Score::getHighScore(int lvl){
    std::ifstream input("derailed.save");
    std::string line;
    while( std::getline( input, line ) ) {
        if(stoi(line.substr(0, line.find(","))) == lvl)
            return stoi(line.substr(line.find(","))); 
    }
    return 0;
}

int Score::eventHandler(const df::Event *p_e) {
}