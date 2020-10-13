#pragma once

#include "Actor.h"
#include "Constants.h"
#include "Emitter.h"

class Player : public Actor {
 public:
  Player();

  void update() override;
  void draw() override;

  void updateTurretDirection(glm::vec3 direction) {
    turret.setDirection(direction);
  }
  void shoot();

 private:
  void clampPosition();

  Emitter turret;  // TODO encapsulate into turret class?
  ofSoundPlayer turretSound;
};
