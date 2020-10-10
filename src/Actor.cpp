#include "Actor.h"

/**
 * @brief Create an Actor with no Sprite
 */
Actor::Actor() : position{glm::vec3(0.0f)} {}

/**
 * @brief Create an Actor with a Sprite
 * @param sprite The desired Sprite
 */
Actor::Actor(const Sprite& sprite)
    : position{glm::vec3(0.0f)}, sprite{sprite} {}

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
void Actor::setPosition(const glm::vec3& position) {
  this->position = position;
}

/**
 * @brief Get the Actor's position
 * @return The Actor's position
 */
glm::vec3 Actor::getPosition() { return position; }

/**
 * @brief Move the Actor up
 */
void Actor::moveUp() {
  // y values shrink upwards
  position.y -= Constants::DEFAULT_MOVEMENT_STEP;
}

/**
 * @brief Move the Actor left
 */
void Actor::moveLeft() { position.x -= Constants::DEFAULT_MOVEMENT_STEP; }

/**
 * @brief Move the Actor down
 */
void Actor::moveDown() {
  // y values grow downwards
  position.y += Constants::DEFAULT_MOVEMENT_STEP;
}

/**
 * @brief Move the Actor right
 */
void Actor::moveRight() { position.x += Constants::DEFAULT_MOVEMENT_STEP; }

// Private Methods
void Actor::updateTransformationMatrix() {
  transformationMatrix = glm::translate(glm::mat4(1.0f), position);
}
