#pragma once

#include "Constants.h"
#include "ofMain.h"

class Sprite {
 public:
  Sprite();

  void draw();

  void setTransformationMatrix(const glm::mat4& transformationMatrix);
  void setImage(const string& filename);

 private:
  void drawPlaceholder();

  bool loaded;
  glm::mat4 transformationMatrix;
  ofImage image;
};
