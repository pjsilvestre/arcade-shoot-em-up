#pragma once

#include "Actor.h"
#include "Constants.h"
#include "Turret.h"

class Player : public Actor {
 public:
  Player();

  void update() override;
  void draw() override;

  void setTurretDirection(const glm::vec3& dir) { turret.setDirection(dir); }

  void moveUp();
  void moveLeft();
  void moveDown();
  void moveRight();
  void startTurret();
  void stop();
  void stopTurret();

 private:
  void clampPosition();
  void integrate() override;

  Turret turret{Turret()};
};
