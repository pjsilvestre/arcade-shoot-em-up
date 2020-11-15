/**
 * @class ExplosionSystem
 * @brief Encapsulates a collection of ExplosionEmitters
 */

#pragma once

#include "ExplosionEmitter.h"

class ExplosionSystem {
 public:
  ExplosionSystem();

  void update();
  void draw();

  void explode(const ofWindowPosEventArgs& collisionPosition);

 private:
  vector<ExplosionEmitter> emitters;
};
