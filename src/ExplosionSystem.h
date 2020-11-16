/**
 * @class ExplosionSystem
 * @brief Encapsulates a collection of ExplosionEmitters
 */

#pragma once

#include "Emitter.h"

class ExplosionSystem {
 public:
  ExplosionSystem();

  void update();
  void draw();

  void explode(const ofWindowPosEventArgs& collisionPosition);

 private:
  class ExplosionEmitter : public Emitter {
   public:
    ExplosionEmitter();
  };

  vector<ExplosionEmitter> emitters;
};
