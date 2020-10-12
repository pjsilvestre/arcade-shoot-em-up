#pragma once

#include "Actor.h"
#include "Constants.h"

class Player : public Actor {
 public:
  // inherit constructors
  using Actor::Actor;

  void update() override;

 private:
  void clampPosition();
};
