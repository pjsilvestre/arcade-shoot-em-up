#pragma once

#include "Constants.h"
#include "ofMain.h"

enum class Integration_Strategy_Type { actor, player, turret, enemy_linear };

class IntegrationStrategy {
 public:
  virtual void integrate(glm::vec3& position, glm::vec3& velocity,
                         glm::vec3& acceleration) = 0;
};

class ActorIntegrationStrategy : public IntegrationStrategy {
 public:
  void integrate(glm::vec3& position, glm::vec3& velocity,
                 glm::vec3& acceleration) override;
};

class PlayerIntegrationStrategy : public IntegrationStrategy {
 public:
  void integrate(glm::vec3& position, glm::vec3& velocity,
                 glm::vec3& acceleration) override;
};

class TurretIntegrationStrategy : public IntegrationStrategy {
 public:
  void integrate(glm::vec3& position, glm::vec3& velocity,
                 glm::vec3& acceleration) override;
};

class EnemyLinearIntegrationStrategy : public IntegrationStrategy {
 public:
  void integrate(glm::vec3& position, glm::vec3& velocity,
                 glm::vec3& acceleration) override;
};
