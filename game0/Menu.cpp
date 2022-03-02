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
#include "LevelMenu.h"


Menu::Menu(){

    setType("Menu");
    setSprite("menu");
    setLocation(df::CENTER_CENTER);
    registerInterest(df::KEYBOARD_EVENT);
    registerInterest(WIN_EVENT);
    hasStarted = 0;
    
}

int Menu::eventHandler(const df::Event *p_e) {

  if (p_e->getType() == df::KEYBOARD_EVENT && hasStarted == 0) {
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
    return 1;
  }
    
  return 0;
}

void Menu::start() {
    
    new LevelMenu;
    setActive(false);
}

//LOAD BEARING WORTHLESS LINE
Menu::~Menu() {} //fixes Vtable error when I build on linux

int Menu::draw() {
  return df::Object::draw();
}