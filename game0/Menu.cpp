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
}

int Menu::eventHandler(const df::Event *p_e) {

  if (p_e->getType() == df::KEYBOARD_EVENT) {
    df::EventKeyboard *p_keyboard_event = (df::EventKeyboard *) p_e;
    switch (p_keyboard_event->getKey()) {
    case df::Keyboard::P: 			// play
      start();
      break;
    case df::Keyboard::Q:			// quit
      GM.setGameOver();
      break;
    default:
      break;
    }
    
  }

  if (p_e->getType() == WIN_EVENT){
    LM.writeLog("bababooey!");
  }

  LM.writeLog("event detected");

  return 1;
}

void Menu::start() {
     setSprite("empty");
    new Board("boards/board_01.txt");
    
}

//LOAD BEARING WORTHLESS LINE
Menu::~Menu() {} //fixes Vtable error when I build on linux

int Menu::draw() {
  return df::Object::draw();
}