//
// game.cpp
// 

// Engine includes.
#include "GameManager.h"
#include "LogManager.h"
#include "ResourceManager.h"
#include "Space.h"
#include "Board.h"

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
    RM.loadSprite("sprites/train_up_normal.txt", "train_up_n");
    new Board("boards/board_02.txt");
}

void populateWorld() {
}