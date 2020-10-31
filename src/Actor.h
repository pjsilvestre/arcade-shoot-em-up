#pragma once

#include "Constants.h"
#include "IntegrationStrategy.h"
#include "Sprite.h"
#include "Utility.h"

class Actor {
 public:
  ~Actor() {}  // handled by ActorSystem.deleteDeadActors()

  virtual void update();
  virtual void draw();

  void setLifespan(float lifespan) { this->lifespan = lifespan; }
  int getLifespan() { return lifespan; }
  void setPosition(const glm::vec3& position) { this->position = position; }
  IntegrationStrategy* getIntegrationStrategy() { return integrationStrategy; }
  void setIntegrationStrategy(IntegrationStrategy* strategy) {
    integrationStrategy = strategy;
  }
  void setSprite(const Sprite& sprite) { this->sprite = sprite; }

  float getAge();
  void move(const glm::vec3& direction);

 protected:
  void integrate();
  void updateTransform();

  float initialAcceleration{Constants::ACTOR_INITIAL_ACCELERATION};
  float lifespan{Constants::ACTOR_LIFESPAN};
  float spawnTime{ofGetElapsedTimef()};
  IntegrationStrategy* integrationStrategy{nullptr};
  glm::mat4 transform{glm::mat4(0.0f)};
  Sprite sprite;
  glm::vec3 position{glm::vec3(0.0f)};
  glm::vec3 velocity{glm::vec3(0.0f)};
  glm::vec3 acceleration{glm::vec3(0.0f)};
};
