// Engine includes
#include "Color.h"
#include "EventKeyboard.h"
#include "LogManager.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
#include "EventStep.h"
//Other Includes
#include "Menu.h"
#include "Board.h"
#include "EventWin.h"


Menu::Menu(std::string type, std::string sprite){

    setType(type);
    setSprite(sprite);
    setLocation(df::CENTER_CENTER);
    registerInterest(df::KEYBOARD_EVENT);
    registerInterest(WIN_EVENT);
    hasStarted = 0;
    
}

int Menu::eventHandler(const df::Event *p_e) {

  if (p_e->getType() == df::KEYBOARD_EVENT && hasStarted == 0) {
    LM.writeLog("keyboard event registered - menu");
    df::EventKeyboard *p_keyboard_event = (df::EventKeyboard *) p_e;
    switch (p_keyboard_event->getKey()) {
    case df::Keyboard::P: 			// play
      if(hasStarted == 0){
        start();
        hasStarted = 1;
      }
      break;
    case df::Keyboard::Q:			// quit
      GM.setGameOver();
      break;
    default:
      break;
    }
    
  }

  if (p_e->getType() == WIN_EVENT){
    LM.writeLog("win event registered - menu");
    setSprite("win");
    hasStarted = 0;
    WM.markForDelete(level);
  }
    
  return 1;
}

void Menu::start() {
    setSprite("empty");
    level = new Board("boards/board_01.txt");
    
}

//LOAD BEARING WORTHLESS LINE
Menu::~Menu() {} //fixes Vtable error when I build on linux

int Menu::draw() {
  return df::Object::draw();
}