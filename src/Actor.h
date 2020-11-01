/**
 * @class Actor
 * @brief Encapsulates movable, drawable objects
 */

#pragma once

#include "Constants.h"
#include "IntegrationStrategy.h"
#include "Sprite.h"

class Actor {
 public:
  // when an Actor is destroyed, its IntegrationStrategy may still be allocated
  // on the heap. If the Actor was contained within an ActorSystem, then the
  // IntegrationStrategy should have been deleted. In all other cases, the
  // IntegrationStrategy must be deleted manually. TODO better solution?
  ~Actor() {}

  virtual void update();
  virtual void draw();

  void setLifespan(float lifespan) { this->lifespan = lifespan; }
  int getLifespan() { return lifespan; }
  void setPosition(const glm::vec3& position) { this->position = position; }
  glm::vec3 getPosition() { return position; }
  // TODO better solution than giving out raw pointers?
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
