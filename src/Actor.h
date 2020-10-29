#pragma once

#include "Constants.h"
#include "Sprite.h"
#include "Utility.h"

class Actor {
 public:
  Actor();
  Actor(const Sprite& sprite);

  virtual void update();
  virtual void draw();

  void setLifespan(int lifespan) { this->lifespan = lifespan; }
  int getLifespan() { return lifespan; }
  void setPosition(const glm::vec3& position) { this->position = position; }
  glm::vec3 getPosition() { return position; }
  void setVelocity(const glm::vec3& velocity) { this->velocity = velocity; }
  glm::vec3 getVelocity() { return velocity; }
  void setAcceleration(const glm::vec3& accel) { this->acceleration = accel; }
  glm::vec3 getAcceleration() { return acceleration; }

  float getAge();
  void move(const glm::vec3& direction);
  void moveUp();
  void moveLeft();
  void moveDown();
  void moveRight();
  void dampMotion();

 private:
  void updatePosition();
  void updateTransformationMatrix();

  float spawnTime;
  float lifespan;
  glm::vec3 position;
  glm::vec3 velocity;
  glm::vec3 acceleration;
  glm::mat4 transformationMatrix;
  Sprite sprite;
};
