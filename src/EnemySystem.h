/**
 * @class EnemySystem
 * @brief Encapsulates a collection of EnemySpawners
 */

#pragma once

#include "Emitter.h"

class EnemySystem {
 public:
  EnemySystem();
  ~EnemySystem();

  void update();
  void draw();

  vector<glm::vec3> getEnemyPositions();
  void removeNear(const glm::vec3& point, float distance);
  void start();
  void notifyCollision(const ofWindowPosEventArgs& collisionPosition);

  ofEvent<const ofWindowPosEventArgs> actorCollided;

 private:
  class EnemyEmitter : public Emitter {
   public:
    EnemyEmitter();
  };

  void addListeners();
  void removeListeners();

  EnemyEmitter topSpawner;
  EnemyEmitter leftSpawner;
  vector<EnemyEmitter*> spawners;
};
