#pragma once

#include "ofMain.h"
#include "Constants.h"

class Sprite {
 public:
  Sprite();
  Sprite(string fileName);
  void setTransformationMatrix(glm::mat4 transformationMatrix);
  void draw();

 private:
  bool loaded;
  ofImage image;
  glm::mat4 transformationMatrix;
};
