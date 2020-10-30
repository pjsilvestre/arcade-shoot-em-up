#pragma once

#include "Constants.h"
#include "Sprite.h"
#include "Utility.h"

class Actor {
 public:
  virtual void update();
  virtual void draw();

  void setLifespan(int lifespan) { this->lifespan = lifespan; }
  int getLifespan() { return lifespan; }
  void setPosition(const glm::vec3& position) { this->position = position; }
  void setSprite(const Sprite& sprite) { this->sprite = sprite; }

  float getAge();
  void move(const glm::vec3& direction);

 protected:
  virtual void integrate();
  void updateTransformationMatrix();

  float accelerationDamping{Constants::ACTOR_ACCELERATION_DAMPING};
  float initialAcceleration{Constants::ACTOR_INITIAL_ACCELERATION};
  float lifespan{Constants::ACTOR_LIFESPAN};
  float maxVelocity{Constants::ACTOR_MAX_VELOCITY};
  float spawnTime{ofGetElapsedTimef()};
  float velocityDamping{Constants::ACTOR_VELOCITY_DAMPING};
  glm::vec3 position{glm::vec3(0.0f)};
  glm::vec3 velocity{glm::vec3(0.0f)};
  glm::vec3 acceleration{glm::vec3(0.0f)};
  glm::mat4 transformationMatrix{glm::mat4(0.0f)};
  Sprite sprite{Sprite()};
};
