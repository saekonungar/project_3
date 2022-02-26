// Engine includes
#include "Color.h"
#include "EventKeyboard.h"
#include "LogManager.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "WorldManager.h"
//Other Includes
#include "Menu.h"
#include "Board.h"

Menu::Menu(){
    setType("Menu");

    setSprite("menu");

    setLocation(df::CENTER_CENTER);

    registerInterest(df::KEYBOARD_EVENT);

}

int Menu::draw() {
  return df::Object::draw();
}