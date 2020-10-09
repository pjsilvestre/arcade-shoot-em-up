#pragma once
#include "ofMain.h"

class Sprite {
 public:
  Sprite();
  Sprite(string fileName);
  bool isLoaded();
  void setTransformationMatrix(glm::mat4 transformationMatrix);
  void draw();

 private:
  bool loaded;
  ofImage image;
  glm::mat4 transformationMatrix;
};
