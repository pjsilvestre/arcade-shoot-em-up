#include "Sprite.h"

/**
 * @brief Creates a Sprite with no image
 */
Sprite::Sprite() : loaded{false} {}

/**
 * @brief Creates a sprite with an image
 * @param fileName The name of the image to load from bin/data
 */
Sprite::Sprite(const string& fileName) {
  if (image.load(fileName)) {
    loaded = true;
  } else {
    loaded = false;
    cerr << fileName << " not found" << endl;
  }
}

/**
 * @brief Draws the Sprite
 */
void Sprite::draw() {
  ofPushMatrix();
  ofMultMatrix(transformationMatrix);
  if (loaded) {
    image.setAnchorPercent(0.5f, 0.5f);
    ofEnableAlphaBlending();
    ofSetColor(ofColor::white, 255);
    image.draw(0, 0);
    ofDisableAlphaBlending();
  } else {
    drawPlaceholder();
  }
  ofPopMatrix();
}

/**
 * @brief Sets the Sprite's transformation matrix
 */
void Sprite::setTransformationMatrix(const glm::mat4& transformationMatrix) {
  this->transformationMatrix = transformationMatrix;
}

void Sprite::drawPlaceholder() {
  ofSetColor(ofColor::hotPink);
  ofDrawRectangle(glm::vec3(0.0f - Constants::SPRITE_DIMENSIONS / 2.0f,
                            0.0f - Constants::SPRITE_DIMENSIONS / 2.0f, 0.0f),
                  Constants::SPRITE_DIMENSIONS, Constants::SPRITE_DIMENSIONS);
}
