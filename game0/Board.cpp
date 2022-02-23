#include "Board.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Board::Board(const char* filename) {
	setType("Board");
	board_loaded = false;

	//SET UP BOARD based on input

	//open file
	//FILE *file;
	//fopen_s(&file, filename, "r");

	//try this again
	ifstream board_file;
	board_file.open(filename);

	string line;

	if (board_file.is_open()) {
		getline(board_file, line);
		cout << line << '\n';
	}

	//read size

}

//events to handle: 
//keyboard event (if puzzle being played)
//checks the space in the direction of the attempted move.
//if the action is possible, generates a move event
//this move event is sent to the train
//it then checks the state of the board for a win, loss, etc
int Board::eventHandler(const df::Event* p_e) {
	return 0;
}