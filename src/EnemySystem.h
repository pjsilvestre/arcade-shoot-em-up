/**
 * @class EnemySystem
 * @brief Encapsulates a collection of EnemySpawners
 */

#pragma once

#include "EnemySpawner.h"

class EnemySystem {
 public:
  EnemySystem();
  ~EnemySystem();

  void update();
  void draw();

  void removeNear(const glm::vec3& point, float distance);
  void start();
  void notifyCollision(const ofEventArgs& unusedArg);

  ofEvent<const ofEventArgs> actorCollided;

 private:
  void addListeners();
  void removeListeners();

  EnemySpawner topSpawner;
  EnemySpawner leftSpawner;
  vector<EnemySpawner> spawners;
};
