#pragma once

#include "ofMain.h"
#include "Constants.h"

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
