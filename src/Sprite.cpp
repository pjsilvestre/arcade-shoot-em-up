#include "Sprite.h"

/**
 * @brief Draws this Sprite
 */
void Sprite::draw() {
  ofPushMatrix();
  ofMultMatrix(transform);
  if (loaded) {
    image.setAnchorPercent(0.5f, 0.5f);
    image.draw(0, 0);
  } else {
    drawPlaceholder();
  }
  ofPopMatrix();
}

/**
 * @brief Sets this Sprite's transformation matrix
 */
void Sprite::setTransform(const glm::mat4& transform) {
  this->transform = transform;
}

/**
 * @brief Loads an image for this Sprite
 * @param filename The image to load from bin/data
 */
void Sprite::loadImage(const string& filename) {
  if (image.load(filename)) {
    loaded = true;
  } else {
    loaded = false;
    cerr << filename << " not found" << endl;
  }
}

//-Private Methods----------------------------------------------

void Sprite::drawPlaceholder() {
  ofSetColor(ofColor::hotPink);
  ofDrawRectangle(
      glm::vec3(0.0f - defaultWidth / 2.0f, 0.0f - defaultHeight / 2.0f, 0.0f),
      defaultWidth, defaultHeight);
}
