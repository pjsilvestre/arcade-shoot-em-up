#pragma once

#include "Command.h"
#include "ofMain.h"

class InputHandler {
 public:
  InputHandler();
  ~InputHandler();

  Command* handleInput(int key);

 private:
  Command* keyW;
  Command* keyA;
  Command* keyS;
  Command* keyD;

  // Command* keyUp;
  // Command* keyLeft;
  // Command* keyDown;
  // Command* keyRight;
};
