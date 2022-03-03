// This manages the score, the level timer (which the score is derived from), and the saves (because this is always persistent);
#include "Score.h"
#include "LevelMenu.h"
#include "LogManager.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Event.h"
#include "EventStep.h"
#include "EventWin.h"
#include <string>

Score::Score(){
    playing = 0;
    registerInterest(WIN_EVENT);
    registerInterest(df::STEP_EVENT);
    setViewString(score);
    int timer = 255;
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
    input.close();
    return 0;
}

void Score::setHighScore(int lvl, int score){
    std::ifstream input("derailed.save");
    std::ofstream output("derailed.save");
    std::string line;
    while( std::getline( input, line ) ) {
        if(stoi(line.substr(0, line.find(","))) == lvl && )
            line = line.substr(0, line.find(",")) + std::to_string(score);
        else{
            output << std::to_string(lvl) + "," + std::to_string(score);
        }
            
    }
    output.close();
    input.close();
}

void setState(int state){
    playing = state;
}

int Score::eventHandler(const df::Event *p_e) {
    if (p_e->getType() == df::STEP_EVENT && playing == 1) {
        if(timer > 0){
            timer -= 1;
        }
    }

    if (p_e->getType() == WIN_EVENT){
        score = 5 * (timer + 1);
        setHighScore(LevelMenu::getLevel(),score);
        score = 0;
        timer = 255;
    }
}

