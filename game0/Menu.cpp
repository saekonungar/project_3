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


Menu::Menu(){
    setType("Menu");
    setSprite("menu");
    setLocation(df::CENTER_CENTER);
    level = new Board("boards/board_01.txt");
    registerInterest(df::KEYBOARD_EVENT);
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
    return 1;
  }

  if (p_e->getType() == WIN_EVENT) {
    WM.markForDelete(level);
    setSprite("win");
    setType("Win");
    setActive(true);
  }
}

void Menu::start() {

    level = new Board("boards/board_01.txt");
    setSprite('empty');
}

//LOAD BEARING WORTHLESS LINE
Menu::~Menu() {} //fixes Vtable error when I build on linux

int Menu::draw() {
  return df::Object::draw();
}