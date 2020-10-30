#include "Sprite.h"

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

/**
 * @brief Sets this Sprite's image
 * @param filename The image to load from bin/data
 */
void Sprite::setImage(const string& filename) {
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
  ofDrawRectangle(glm::vec3(0.0f - Constants::SPRITE_DIMENSIONS / 2.0f,
                            0.0f - Constants::SPRITE_DIMENSIONS / 2.0f, 0.0f),
                  Constants::SPRITE_DIMENSIONS, Constants::SPRITE_DIMENSIONS);
}
