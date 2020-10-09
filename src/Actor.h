#pragma once

#include "Sprite.h"

const float DEFAULT_MOVEMENT_STEP{30.0f};

class Actor {
 public:
  Actor();
  Actor(Sprite sprite);
  void update();
  void draw();
  void setPosition(glm::vec3 position);
  glm::vec3 getPosition();
  void moveUp();
  void moveLeft();
  void moveDown();
  void moveRight();

 private:
  void updateTransformationMatrix();

  Sprite sprite;
  glm::vec3 position;
  glm::mat4 transformationMatrix;
};
