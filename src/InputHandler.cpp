#include "InputHandler.h"

InputHandler::InputHandler() {
  keyW = new MoveUp();
  keyA = new MoveLeft();
  keyS = new MoveDown();
  keyD = new MoveRight();
}

InputHandler::~InputHandler() {
  delete keyW;
  keyW = nullptr;
  delete keyA;
  keyA = nullptr;
  delete keyS;
  keyS = nullptr;
  delete keyD;
  keyD = nullptr;
}

Command* InputHandler::handleInput(int key) {
  switch (key) {
    case 'w':
      return keyW;
    case 'a':
      return keyA;
    case 's':
      return keyS;
    case 'd':
      return keyD;
    default:
      return NULL;
  }
}