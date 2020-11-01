/**
 * @class Emitter
 * @brief Encapsulates generic spawning of Actors with force-based movement
 */

#pragma once

#include "ActorSystem.h"
#include "Constants.h"
#include "IntegrationStrategy.h"

class Emitter {
 public:
  void update();
  void draw();

  int getActorCollidedCount() { return actors.getActorCollidedCount(); }
  void setRate(float rate) { this->ratePerSecond = rate; }
  void setIntegrationStrategyType(Integration_Strategy_Type strategy) {
    this->integrationStrategyType = strategy;
  }
  void setSprite(const Sprite& sprite) { this->sprite = sprite; }
  void setDirection(const glm::vec3& direction) { this->direction = direction; }
  void setPosition(const glm::vec3& position) { this->position = position; }

  vector<glm::vec3> getActorPositions();
  void removeNear(const glm::vec3& point, float distance);
  void start();
  void stop();
  void setCollisionSound(const string& filename);
  void setEmissionSound(const string& filename);

 protected:
  void emit();

  bool soundLoaded{false};
  bool started{false};
  float actorLifespan{Constants::ACTOR_LIFESPAN};
  float magnitude{Constants::EMITTER_MAGNITUDE};
  float ratePerSecond{Constants::SPRITES_PER_SECOND};
  float timeOfLastEmittedActorMilliseconds{0.0f};
  ActorSystem actors;
  Integration_Strategy_Type integrationStrategyType{
      Integration_Strategy_Type::actor};
  ofSoundPlayer emissionSound;
  Sprite sprite;
  glm::vec3 direction{glm::vec3(0.0f)};
  glm::vec3 position{glm::vec3(0.0f)};
};
