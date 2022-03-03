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
int Score::score = 0;
int Score::level = 1;

//return the number of levels completed by the player
int Score::getLargestLevel(){
    std::ifstream input("derailed.save");
    std::string line;
    int largest_level = 1;
    while( std::getline( input, line ) ) {
        largest_level = stoi(line.substr(0, line.find(","))); 
    }
    return largest_level;
    input.close();
}

int Score::getHighScore(int lvl){
    std::ifstream input("derailedsave.txt");
    std::string line;
    while(input >> line) {
        if(stoi(line.substr(0, line.find(","))) == lvl)
            return stoi(line.substr(line.find(",")+1)); 
    }
    input.close();
    return 0;
}

void Score::setHighScore(int lvl, int score){
    //open proper files
    std::ifstream input("derailedsave.txt");
    std::ofstream output("derailedsavetemp.txt");
    std::string line;
    std::string strTemp;
    bool line_found = false;

    while(input >> line)
    {
        if (stoi(line.substr(0, line.find(","))) == lvl){
            LM.writeLog("AAAA");
            int temp_score = stoi(line.substr(line.find(",") + 1));
            if (score > temp_score) temp_score = score;
            strTemp = line.substr(0, line.find(",")) + "," + std::to_string(score);
            line_found = true;
        } else strTemp = line;
        strTemp += "\n";
        output << strTemp;
    }
    output.close();
    input.close();

    //add line if not present
    if (!line_found) {
        LM.writeLog("adding new line");
        std::ofstream temp_output("derailedsavetemp.txt", std::ios_base::app);
        temp_output << level << "," << score << "\n";
        temp_output.close();
    }
    
    //now copy over to actual save file
    std::ifstream cp_input("derailedsavetemp.txt");
    std::ofstream cp_output("derailedsave.txt");

    while (cp_input >> line) {
        cp_output << line << "\n";
    }

    cp_output.close();
    cp_input.close();
}

void Score::startScore(int current_level){
    LM.writeLog("starting score on level %d", current_level);
    playing = true;
    level = current_level;
}

int Score::getScore() {
    return score;
}

void Score::handleTimer() {
    if (playing && timer > 0) {
        timer -= 1;
    }
}

void Score::onWin(int level) {
    score = 5 * (timer + 1);
    setHighScore(level, score);
    score = 0;
    timer = 255;
    playing = false;
}