#pragma once

#include "ActorSystem.h"

class Emitter {
 public:
  Emitter(){};
  Emitter(const Sprite& sprite);

  void update();
  void draw();

  void emit();

 private:
  Sprite sprite;
  ActorSystem actors;
};
