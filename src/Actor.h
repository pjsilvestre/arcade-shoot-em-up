#pragma once

#include "Constants.h"
#include "Sprite.h"

class Actor {
 public:
  Actor();
  Actor(const Sprite& sprite);

  virtual void update();
  void draw();

  void setPosition(const glm::vec3& position);
  glm::vec3 getPosition();
  void setVelocity(const glm::vec3& velocity);
  glm::vec3 getVelocity();
  void setAcceleration(const glm::vec3& acceleration);
  glm::vec3 getAcceleration();

  // TODO update following methods to use position, velocity, and acceleration
  void moveUp();
  void moveLeft();
  void moveDown();
  void moveRight();

 private:
  void updateTransformationMatrix();

  Sprite sprite;
  glm::vec3 position;
  glm::vec3 velocity;
  glm::vec3 acceleration;
  glm::mat4 transformationMatrix;
};
