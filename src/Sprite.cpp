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

    // center image relative to Sprite
    image.setAnchorPercent(0.5, 0.5);
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
  image.draw(0, 0);
  ofPopMatrix();
}
