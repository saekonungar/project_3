// This manages the score, the level timer (which the score is derived from), and the saves (because this is always persistent);
#include "Score.h"
#include "LogManager.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "EventStep.h"


Score::Score(){
    std::ifstream input("derailed.save");
    std::string line;
    while( std::getline( input, line ) ) {
        std::string token = line.substr(0, line.find(",")); 
    }

}