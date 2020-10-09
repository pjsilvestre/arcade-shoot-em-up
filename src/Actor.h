#pragma once
#include "Sprite.h"

class Actor {
 public:
  Actor();
  Actor(Sprite sprite);
  void update();
  void draw();
  void setPosition(glm::vec3 position);

 private:
  void updateTransformationMatrix();

  Sprite sprite;
  glm::vec3 position;
  glm::mat4 transformationMatrix;
};
