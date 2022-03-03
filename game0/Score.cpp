// This manages the score, the level timer (which the score is derived from), and the saves (because this is always persistent);
#include "Score.h"
#include "LevelMenu.h"
#include "LogManager.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "Event.h"
#include <string>

int Score::timer = 255;
bool Score::playing = false;
int Score::level = 1;
int Score::score = 0;

int Score::getLargestLevel(){
    std::ifstream input("derailed.save");
    std::string line;
    while( std::getline( input, line ) ) {
        level = stoi(line.substr(0, line.find(","))); 
    }
    return level;
    input.close();
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
        if(stoi(line.substr(0, line.find(","))) == lvl && playing)
            line = line.substr(0, line.find(",")) + std::to_string(score);
        else{
            output << std::to_string(lvl) + "," + std::to_string(score);
            break;
        }
            
    }
    output.close();
    input.close();
}

void Score::setState(bool state){
    playing = state;
}

int Score::getScore() {
    return score;
}

void Score::handleTimer() {
    if (timer > 0) {
        timer -= 1;
    }
}

void Score::onWin() {
    score = 5 * (timer + 1);
    //setHighScore(LevelMenu::getLevel(),score);
    score = 0;
    timer = 255;
}