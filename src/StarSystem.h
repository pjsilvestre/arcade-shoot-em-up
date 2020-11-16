/**
 * @class StarSystem
 * @brief Encapsulates a collection of StarEmitters to draw in the background
 */

#pragma once

#include "Emitter.h"

class StarSystem {
 public:
  StarSystem();

  void update();
  void draw();

  void start();

 private:
  class StarEmitter : public Emitter {
   public:
    StarEmitter();
  };

  StarEmitter nearEmitter;
  StarEmitter midEmitter;
  StarEmitter farEmitter;
  vector<Emitter> starEmitters;
};
