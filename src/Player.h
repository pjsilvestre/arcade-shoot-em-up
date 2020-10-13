#pragma once

#include "Actor.h"
#include "Emitter.h"
#include "Constants.h"

class Player : public Actor {
 public:
  Player();

  void update() override;
  void draw() override;

  void shoot();

 private:
  void clampPosition();

  Emitter turret;
};
