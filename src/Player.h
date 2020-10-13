#pragma once

#include "Actor.h"
#include "Constants.h"

class Player : public Actor {
 public:
  Player();
  void update() override;

 private:
  void clampPosition();
};
