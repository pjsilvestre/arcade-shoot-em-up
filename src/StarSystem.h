/**
 * @class StarSystem
 * @brief Encapsulates a collection of StarEmitters to draw in the background
 */

#pragma once

#include "Constants.h"
#include "StarEmitter.h"

class StarSystem {
 public:
  StarSystem();

  void update();
  void draw();

  void start();

 private:
  StarEmitter nearEmitter;
  StarEmitter midEmitter;
  StarEmitter farEmitter;
  vector<Emitter> starEmitters;
};
