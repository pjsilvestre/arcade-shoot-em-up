/**
 * @class Player
 * @brief Encapsulates an Actor controllable by the user
 */

#pragma once

#include "Emitter.h"
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
  void removeMissiles(const ofWindowPosEventArgs& unusedArg);
  void startTurret();
  void stop();
  void stopTurret();

  ofEvent<const ofEventArgs> missileLaunched;

 private:
  class Turret : public Emitter {
   public:
    Turret();
  };

  void clampPosition();

  bool turretEnabled{true};
  Turret turret;
};
