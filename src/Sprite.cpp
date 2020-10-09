#include "Sprite.h"

/**
 * @brief Creates a sprite with no image
 */
Sprite::Sprite() : loaded{false} {}

/**
 * @brief Creates a sprite with an image
 * @param fileName The name of the image to load from bin/data
 */
Sprite::Sprite(string fileName) {
  if (image.load(fileName)) {
    loaded = true;
  } else {
    loaded = false;
    cerr << fileName << " not found" << endl;
  }
}

/**
 * @brief Returns if image is loaded
 * @return True if image is loaded, false otherwise
 */
bool Sprite::isLoaded() { return loaded; }

/**
 * @brief Sets the Sprite's transformation matrix
 */
void Sprite::setTransformationMatrix(glm::mat4 transformationMatrix) {
  this->transformationMatrix = transformationMatrix;
}

/**
 * @brief Draws the Sprite
 */
void Sprite::draw() {
  ofPushMatrix();
  ofMultMatrix(transformationMatrix);
  if (loaded) {
    image.setAnchorPercent(0.5f, 0.5f);
    image.draw(0, 0);
  }
  else {
    ofDrawRectangle(glm::vec3(0.0f, 0.0f, 0.0f), 128.0f, 128.0f);
  }
  ofPopMatrix();
}
