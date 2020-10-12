#include "Actor.h"

/**
 * @brief Create an Actor with no Sprite
 */
Actor::Actor()
    : age{0},
      lifespan{Constants::LIFESPAN},
      position{glm::vec3(0.0f)},
      velocity{glm::vec3(0.0f)},
      acceleration{glm::vec3(0.0f)} {}

/**
 * @brief Create an Actor with a Sprite
 * @param sprite The desired Sprite
 */
Actor::Actor(const Sprite& sprite) : Actor() { this->sprite = sprite; }

/**
 * @brief Update the Actor's state
 */
void Actor::update() {
  age++;
  updatePosition();
  updateVelocity();
  updateAcceleration();
  updateTransformationMatrix();
  sprite.setTransformationMatrix(transformationMatrix);
}

/**
 * @brief Draw the Actor
 */
void Actor::draw() { sprite.draw(); }

/**
 * @brief Move the Actor up
 */
void Actor::moveUp() {
  // y values shrink upwards
  acceleration.y = -Constants::ACCELERATION;
}

/**
 * @brief Move the Actor left
 */
void Actor::moveLeft() { acceleration.x = -Constants::ACCELERATION; }

/**
 * @brief Move the Actor down
 */
void Actor::moveDown() {
  // y values grow downwards
  acceleration.y = Constants::ACCELERATION;
}

/**
 * @brief Move the Actor right
 */
void Actor::moveRight() { acceleration.x = Constants::ACCELERATION; }

/**
 * @brief Stop the Actor
 */
void Actor::stop() {
  velocity = glm::vec3(0.0f);
  acceleration = glm::vec3(0.0f);
}

// Private Methods

void Actor::updatePosition() {
  // TODO integrate framerate as time delta
  // TODO improve responsiveness?
  position += velocity;
}

void Actor::updateVelocity() {
  velocity += acceleration;

  velocity.x = Utility::clamp(velocity.x, -Constants::MAX_VELOCITY,
                              Constants::MAX_VELOCITY);
  velocity.y = Utility::clamp(velocity.y, -Constants::MAX_VELOCITY,
                              Constants::MAX_VELOCITY);
}

void Actor::updateAcceleration() {
  // TODO non-linear acceleration?
}

void Actor::updateTransformationMatrix() {
  transformationMatrix = glm::translate(glm::mat4(1.0f), position);
}
