//
// game.cpp
// 

// Engine includes.
#include <stdio.h>
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Space.h"
#include "Board.h"
#include "Menu.h"

//methods
void loadResources();
void populateWorld();

int main(int argc, char *argv[]) {

  // Start up game manager.
  if (GM.startUp())  {
    LM.writeLog("Error starting game manager!");
    GM.shutDown();
    return 0;
  }

  // Set flush of logfile during development (when done, make false).
  LM.setFlush(true);

  // Show splash screen.
  //df::splash();

  //load game resources.
  loadResources();

  //populate the game world with objects
  populateWorld();

  //RUN TIME
  GM.run();

  // Shut everything down.
  GM.shutDown();
}

void loadResources() {
    RM.loadSprite("sprites/board_space_spr.txt", "space");

    //load train sprites
    RM.loadSprite("sprites/train_up_normal.txt", "train_up_n");
    RM.loadSprite("sprites/train_down_normal.txt", "train_down_n");
    RM.loadSprite("sprites/train_left_normal.txt", "train_left_n");
    RM.loadSprite("sprites/train_right_normal.txt", "train_right_n");

    //load track sprites
    RM.loadSprite("sprites/tracks_vertical_spr.txt", "tracks_vertical");
    RM.loadSprite("sprites/tracks_horizontal_spr.txt", "tracks_horizontal");
    RM.loadSprite("sprites/tracks_corner_1_spr.txt", "tracks_corner1");
    RM.loadSprite("sprites/tracks_corner_2_spr.txt", "tracks_corner2");
    RM.loadSprite("sprites/tracks_corner_3_spr.txt", "tracks_corner3");
    RM.loadSprite("sprites/tracks_corner_4_spr.txt", "tracks_corner4");
}

void populateWorld() {
    new Menu();
    //new Board("boards/board_01.txt");
}