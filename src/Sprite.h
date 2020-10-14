#pragma once

#include "Constants.h"
#include "ofMain.h"

class Sprite {
 public:
  Sprite();
  Sprite(const string& fileName);

  void draw();

  void setTransformationMatrix(const glm::mat4& transformationMatrix);

 private:
  void drawPlaceholder();

  bool loaded;
  glm::mat4 transformationMatrix;
  ofImage image;
};
