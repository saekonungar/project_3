#include "Board.h"
#include "DisplayManager.h"
#include "Vector.h"
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

	//read board dimensions
	string line;
	if (board_file.is_open()) {
		getline(board_file, line);
	}
	board_rows = std::stoi(line);
	if (board_file.is_open()) {
		getline(board_file, line);
	}
	board_columns = std::stoi(line);

	//set initial vector position
	df::Vector v;

	//initial x: total horizontal size, cut in half, minus half of the total horizontal size of the board
	int x_start = (DM.getHorizontal() / 2) - (board_columns * 10) / 2;
	v.setX(x_start); 
	v.setY((DM.getVertical() / 2) - (board_rows * 5) / 2); //same for Y

	//go through each row
	for (int i = 0; i < board_rows; i++) {
		//get the row
		getline(board_file, line);

		//go through each char in the current row
		for (int j = 0; j < board_columns; j++) {
			if (line.at(j) == '1') {
				Space* s = new Space(v);
				empty_spaces.insert(s);
			}
			if (line.at(j) == 'x') {
				Space* s = new Space(v);
				empty_spaces.insert(s);
				train = new Train(s);
			}
			v.setX(v.getX() + 10);
		}
		v.setX(x_start);
		v.setY(v.getY()+5);
	}
	board_file.close();
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