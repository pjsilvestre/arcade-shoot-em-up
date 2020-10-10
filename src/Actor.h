#pragma once

#include "Sprite.h"
#include "Constants.h"


class Actor {
 public:
  Actor();
  Actor(const Sprite& sprite);

  virtual void update();
  void draw();

  void setPosition(const glm::vec3& position);
  glm::vec3 getPosition();

  void moveUp();
  void moveLeft();
  void moveDown();
  void moveRight();

 private:
  void updateTransformationMatrix();

  Sprite sprite;
  glm::vec3 position;
  glm::vec3 velocity;
  glm::mat4 transformationMatrix;
};
