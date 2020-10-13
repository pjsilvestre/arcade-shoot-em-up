#pragma once

#include "Actor.h"
#include "Constants.h"
#include "Emitter.h"

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

  Emitter turret;  // TODO encapsulate into turret class?
};
