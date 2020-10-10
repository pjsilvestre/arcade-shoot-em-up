#pragma once

#include "Constants.h"
#include "ofMain.h"

class Sprite {
 public:
  Sprite();
  Sprite(string fileName);
  void setTransformationMatrix(const glm::mat4& transformationMatrix);
  void draw();

 private:
  void drawPlaceholder();

  bool loaded;
  ofImage image;
  glm::mat4 transformationMatrix;
};
