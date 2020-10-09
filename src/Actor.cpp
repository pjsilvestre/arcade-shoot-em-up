#include "Actor.h"

/**
 * @brief Create an Actor with no Sprite
 */
Actor::Actor() {}

/**
 * @brief Create an Actor with a Sprite
 * @param sprite The desired Sprite
 */
Actor::Actor(Sprite sprite) { this->sprite = sprite; }

/**
 * @brief Update the Actor's state
 */
void Actor::update() {
  updateTransformationMatrix();
  sprite.setTransformationMatrix(transformationMatrix);
}

/**
 * @brief Draw the Actor
 */
void Actor::draw() { sprite.draw(); }

/**
 * @brief Set the Actor's position
 * @param position The desired position
 */
void Actor::setPosition(glm::vec3 position) { this->position = position; }

void Actor::updateTransformationMatrix() {
  transformationMatrix = glm::translate(glm::mat4(1.0f), position);
}
