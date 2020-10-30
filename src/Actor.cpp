#include "Actor.h"

/**
 * @brief Updates the Actor's state
 */
void Actor::update() {
  integrate();
  updateTransformationMatrix();
  sprite.setTransformationMatrix(transformationMatrix);
}

/**
 * @brief Draws the Actor
 */
void Actor::draw() { sprite.draw(); }

/**
 * @brief Gets this Actor's age in seconds
 */
float Actor::getAge() { return ofGetElapsedTimef() - spawnTime; }

/**
 * @brief Moves the Actor in a given direction
 * @param direction The desired direction
 */
void Actor::move(const glm::vec3& direction) { acceleration = direction; }

/**
 * @brief Moves the Actor up
 */
void Actor::moveUp() {
  // y values shrink upwards
  acceleration.y = -initialAcceleration;
}

/**
 * @brief Moves the Actor left
 */
void Actor::moveLeft() { acceleration.x = -initialAcceleration; }

/**
 * @brief Moves the Actor down
 */
void Actor::moveDown() {
  // y values grow downwards
  acceleration.y = initialAcceleration;
}

/**
 * @brief Moves the Actor right
 */
void Actor::moveRight() { acceleration.x = initialAcceleration; }

//-Private Methods----------------------------------------------

void Actor::integrate() {
  float timestep = 1.0f / ofGetFrameRate();

  position += velocity * timestep;

  if (glm::length(velocity) < Constants::ACTOR_MAX_VELOCITY) {
    velocity += acceleration * timestep;
  }

  velocity *= velocityDamping;
  acceleration *= accelerationDamping;
}

void Actor::updateTransformationMatrix() {
  transformationMatrix = glm::translate(glm::mat4(1.0f), position);
}
