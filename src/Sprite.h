#pragma once

#include "Constants.h"
#include "ofMain.h"

class Sprite {
 public:
  void draw();

  void setTransformationMatrix(const glm::mat4& transformationMatrix);
  void setImage(const string& filename);

 private:
  void drawPlaceholder();

  bool loaded{false};
  glm::mat4 transformationMatrix{glm::mat4()};
  ofImage image{ofImage()};
};
