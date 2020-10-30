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
  float defaultHeight{Constants::SPRITE_DIMENSIONS};
  float defaultWidth{Constants::SPRITE_DIMENSIONS};
  glm::mat4 transformationMatrix{glm::mat4(-FLT_MAX)};
  ofImage image{ofImage()};
};
