/**
 * @class Player
 * @brief Encapsulates an Actor controllable by the user
 */

#pragma once

#include "Actor.h"
#include "Constants.h"
#include "Turret.h"
#include "Utility.h"

class Player : public Actor {
 public:
  Player();

  void update() override;
  void draw() override;

  vector<glm::vec3> getMissilePositions();
  void moveUp();
  void moveLeft();
  void moveDown();
  void moveRight();
  void startTurret();
  void stop();
  void stopTurret();

 private:
  void clampPosition();

  Turret turret;
};
