#pragma once

#include "Actor.h"
#include "Constants.h"

class Missile : public Actor {
 public:
  Missile() : Actor(Sprite(Constants::MISSILE_SPRITE())) {
    this->setLifespan(Constants::MISSILE_LIFESPAN);
  }
};
