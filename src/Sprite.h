/**
 * @class Sprite
 * @brief Encapsulates loading and drawing of ofImages
 */

#pragma once

#include "Constants.h"
#include "ofMain.h"

class Sprite {
 public:
  void draw();

  void setTransform(const glm::mat4& transform);
  void loadImage(const string& filename);

 private:
  void drawPlaceholder();

  bool loaded{false};
  float defaultHeight{Constants::SPRITE_DIMENSIONS};
  float defaultWidth{Constants::SPRITE_DIMENSIONS};
  glm::mat4 transform{glm::mat4(-FLT_MAX)};
  ofImage image;
};
