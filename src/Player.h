#pragma once

#include "Actor.h"
#include "Constants.h"
#include "Turret.h"

class Player : public Actor {
 public:
  Player();

  void update() override;
  void draw() override;

  void setTurretDirection(glm::vec3 dir) { turret.setDirection(dir); }
  void setTurretRate(float rate) { turret.setRate(rate); }
  void startTurret();
  void stopTurret();

 private:
  void clampPosition();
  void integrate() override;

  Turret turret{Turret()};
};
